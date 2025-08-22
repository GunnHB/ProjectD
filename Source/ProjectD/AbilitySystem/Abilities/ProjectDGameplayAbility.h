// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ProjectDGameplayAbility.generated.h"

class UPawnCombatComponent;

UENUM()
enum class EProjectDAbilityActivationPolicy
{
	OnTriggered,
	OnGiven,
};

/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	// ~ Begin IAbilitySystemInterface Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	// ~ End IAbilitySystemInterface Interface

	UPROPERTY(EditDefaultsOnly, Category="CharacterAbility")
	EProjectDAbilityActivationPolicy AbilityActivationPolicy = EProjectDAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category="Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;
};
