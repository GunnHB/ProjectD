// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectDBaseAnimInstance.h"
#include "ProjectDCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AProjectDBaseCharacter;
/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDCharacterAnimInstance : public UProjectDBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	TObjectPtr<AProjectDBaseCharacter> OwningCharacter = nullptr;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|Locomotion")
	float GroundSpeed = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|Locomotion")
	bool bHasAcceleration = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|Locomotion")
	float LocomotionDirection = 0.f;
};
