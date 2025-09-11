// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkourComponent.h"

#include "Kismet/KismetSystemLibrary.h"
#include "ProjectD/DevHelper.h"

UParkourComponent::UParkourComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UParkourComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TraceAndDetect();
}

void UParkourComponent::TraceAndDetect()
{
	const FVector StartPoint = GetOwningPawn()->GetActorLocation();
	const FVector EndPoint = StartPoint + GetOwningPawn()->GetActorForwardVector() * TraceDistance;

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwningPawn());

	const bool bHit = UKismetSystemLibrary::CapsuleTraceSingle(GetWorld(), StartPoint, EndPoint, 30.f, 50.f, TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, TraceHitResult, true);

	if (bHit)
		Debug::Print(FString::Printf(TEXT("Trace hit: %s"), *TraceHitResult.GetActor()->GetActorNameOrLabel()));
}
