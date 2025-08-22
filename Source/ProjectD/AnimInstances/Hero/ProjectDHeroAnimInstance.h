// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectD/AnimInstances/ProjectDCharacterAnimInstance.h"

#include "ProjectDHeroAnimInstance.generated.h"

class AProjectDHeroCharacter;
/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDHeroAnimInstance : public UProjectDCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|References")
	TObjectPtr<AProjectDHeroCharacter> OwningHeroCharacter = nullptr;
};
