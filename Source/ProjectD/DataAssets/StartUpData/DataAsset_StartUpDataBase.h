// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UProjectDAbilitySystemComponent;
class UProjectDGameplayAbility;
/**
 * 
 */
UCLASS()
class PROJECTD_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UProjectDAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UProjectDGameplayAbility>> ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UProjectDGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UProjectDGameplayAbility>>& InAbilitiesToGive, UProjectDAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
