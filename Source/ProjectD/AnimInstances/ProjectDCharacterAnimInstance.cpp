// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "ProjectD/Characters/ProjectDBaseCharacter.h"
#include "ProjectD/Components/Movement/ProjectDFootIKComponent.h"

void UProjectDCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AProjectDBaseCharacter>(TryGetPawnOwner());
	if (IsValid(OwningCharacter) != false)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
		OwningFootIKComponent = OwningCharacter->FindComponentByClass<UProjectDFootIKComponent>();
	}
}

void UProjectDCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwningCharacter) == false || IsValid(OwningMovementComponent) == false)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	if (IsValid(OwningFootIKComponent))
	{
		LeftFootIKData = OwningFootIKComponent->GetLeftFootIKData();
		RightFootIKData = OwningFootIKComponent->GetRightFootIKData();
		PelvisOffset = OwningFootIKComponent->GetPelvisOffset();
	}
}
