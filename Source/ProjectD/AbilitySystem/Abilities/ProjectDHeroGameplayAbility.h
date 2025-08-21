// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectDGameplayAbility.h"
#include "ProjectDHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AProjectDHeroController;
class AProjectDHeroCharacter;
/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDHeroGameplayAbility : public UProjectDGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Character|Ability")
	AProjectDHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Character|Ability")
	AProjectDHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Character|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AProjectDHeroCharacter> CachedHeroCharacter = nullptr;
	TWeakObjectPtr<AProjectDHeroController> CachedHeroController = nullptr;
};
