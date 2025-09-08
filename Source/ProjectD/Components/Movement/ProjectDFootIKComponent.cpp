// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDFootIKComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ProjectD/DevHelper.h"
#include "ProjectD/Characters/ProjectDBaseCharacter.h"

UProjectDFootIKComponent::UProjectDFootIKComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UProjectDFootIKComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsValid(SkeletalMeshComponent) == false || GetOwningPawn<AProjectDBaseCharacter>()->GetCharacterMovement()->IsFalling())
	{
		PelvisOffset = 0.f;
		LeftFootIKData.Clear();
		RightFootIKData.Clear();

		return;
	}

	float LeftFootOffset = 0.f;
	float RightFootOffset = 0.f;

	TraceFoot(LeftFootSocketName, LeftFootIKData, LeftFootOffset);
	TraceFoot(RightFootSocketName, RightFootIKData, RightFootOffset);

	PelvisOffset = FMath::Min(LeftFootOffset, RightFootOffset);
}

void UProjectDFootIKComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(SkeletalMeshComponent) == false)
		SkeletalMeshComponent = GetOwningPawn<AProjectDBaseCharacter>()->GetMesh();
}

void UProjectDFootIKComponent::TraceFoot(const FName& SocketName, FFootIKData& OutFootIKData, float& OutOffset)
{
	const FVector SocketLocation = SkeletalMeshComponent->GetSocketLocation(SocketName);
	const FVector TraceStart = FVector(SocketLocation.X, SocketLocation.Y, SocketLocation.Z + TraceDistance);
	const FVector TraceEnd = FVector(SocketLocation.X, SocketLocation.Y, SocketLocation.Z - TraceDistance);

	FHitResult HitResult;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwningPawn());

	const bool bHit = UKismetSystemLibrary::LineTraceSingle(GetWorld(), TraceStart, TraceEnd, TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, HitResult, true);

	if (bHit)
	{
		OutFootIKData.EffectorLocation = HitResult.ImpactPoint;
		OutFootIKData.EffectorRotation = FRotationMatrix::MakeFromZ(HitResult.ImpactNormal).Rotator();

		OutOffset = HitResult.ImpactPoint.Z - SocketLocation.Z;
	}
	else
	{
		OutFootIKData.Clear();
		OutOffset = 0.f;
	}
}