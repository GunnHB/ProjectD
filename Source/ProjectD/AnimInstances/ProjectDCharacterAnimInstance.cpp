// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectD/Characters/ProjectDBaseCharacter.h"

void UProjectDCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AProjectDBaseCharacter>(TryGetPawnOwner());
	if (IsValid(OwningCharacter) != false)
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
}

void UProjectDCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwningCharacter) == false || IsValid(OwningMovementComponent) == false)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
