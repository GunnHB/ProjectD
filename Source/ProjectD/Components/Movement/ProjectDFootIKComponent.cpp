// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDFootIKComponent.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
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
		LeftOffset = 0.f;
		RightOffset = 0.f;
		PelvisOffset = 0.f;

		return;
	}

	FFootIKInfo LeftFootTrace = FootTrace(LeftFootSocketName);
	FFootIKInfo RightFootTrace = FootTrace(RightFootSocketName);

	UpdateFootRotation(DeltaTime, NormalToRotator(LeftFootTrace.ImpactLocation), &LeftFootRotation, 5.f);
	UpdateFootRotation(DeltaTime, NormalToRotator(RightFootTrace.ImpactLocation), &RightFootRotation, 5.f);

	float TempPelvisOffset = UKismetMathLibrary::Min(LeftFootTrace.Offset, RightFootTrace.Offset);

	if (TempPelvisOffset < 0.f == false)
		TempPelvisOffset = 0.f;

	UpdateFootOffset(DeltaTime, TempPelvisOffset, &PelvisOffset, 5.f);
	UpdateFootOffset(DeltaTime, LeftFootTrace.Offset - TempPelvisOffset, &LeftOffset, 5.f);
	UpdateFootOffset(DeltaTime, RightFootTrace.Offset - TempPelvisOffset, &RightOffset, 5.f);
}

void UProjectDFootIKComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(SkeletalMeshComponent) == false)
		SkeletalMeshComponent = GetOwningPawn<AProjectDBaseCharacter>()->GetMesh();
}

FFootIKInfo UProjectDFootIKComponent::FootTrace(const FName& SocketName)
{
	FFootIKInfo TraceInfo;

	FVector SocketLocation = SkeletalMeshComponent->GetSocketLocation(SocketName);
	FVector StartPoint = FVector(SocketLocation.X, SocketLocation.Y, GetOwningPawn()->GetActorLocation().Z);
	FVector EndPoint = FVector(SocketLocation.X, SocketLocation.Y, GetOwningPawn()->GetActorLocation().Z - GetOwningPawn<ACharacter>()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() - TraceDistance);
	
	FHitResult HitResult;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwningPawn());

	const bool bHit = UKismetSystemLibrary::LineTraceSingle(GetWorld(), StartPoint, EndPoint, TraceTypeQuery1, true, ActorsToIgnore, EDrawDebugTrace::None, HitResult, true);
	TraceInfo.ImpactLocation = HitResult.Normal;

	if (HitResult.IsValidBlockingHit())
		TraceInfo.Offset = (HitResult.ImpactPoint - HitResult.TraceEnd).Size() - TraceDistance + 3.f;
	else
		TraceInfo.Offset = 0.f;

	return TraceInfo;
}

void UProjectDFootIKComponent::UpdateFootOffset(float DeltaTime, float TargetValue, float* EffectorValue, float InterpSpeed)
{
	float InterpValue = UKismetMathLibrary::FInterpTo(*EffectorValue, TargetValue, DeltaTime, InterpSpeed);
	*EffectorValue = InterpValue;
}

void UProjectDFootIKComponent::UpdateFootRotation(float DeltaTime, const FRotator& TargetValue, FRotator* FootRotatorValue, float InterpSpeed)
{
	FRotator InterpRotator = UKismetMathLibrary::RInterpTo(*FootRotatorValue, TargetValue, DeltaTime, InterpSpeed);
	*FootRotatorValue = InterpRotator;
}

FRotator UProjectDFootIKComponent::NormalToRotator(const FVector& Vector)
{
	// Roll
	float Atan1 = UKismetMathLibrary::Atan2(Vector.Y, Vector.Z);
	// Pitch
	float Atan2 = UKismetMathLibrary::Atan2(Vector.X, Vector.Z);

	Atan2 *= -1.f;
	FRotator Result = FRotator(Atan2, 0.f, Atan1);

	return Result;
}
