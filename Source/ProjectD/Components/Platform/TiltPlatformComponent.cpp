// Fill out your copyright notice in the Description page of Project Settings.


#include "TiltPlatformComponent.h"

#include "ProjectD/DevHelper.h"

UTiltPlatformComponent::UTiltPlatformComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTiltPlatformComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentPitch += DeltaTime * 8 * (bReverse ? -1.f : 1.f);

	if (bReverse == false)
	{
		if (CurrentPitch >= MaxPitch)
			bReverse = true;
	}
	else
	{
		if (CurrentPitch <= -MaxPitch)
			bReverse = false;
	}

	GetOwner()->SetActorRotation(FRotator(CurrentPitch, 0.f, 0.f));
}
