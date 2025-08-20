// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_StartUpDataBase.h"

#include "ProjectD/AbilitySystem/ProjectDAbilitySystemComponent.h"
#include "ProjectD/AbilitySystem/Abilities/ProjectDGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UProjectDAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UProjectDGameplayAbility>>& InAbilitiesToGive, UProjectDAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
		return;

	for (const TSubclassOf<UProjectDGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (Ability == nullptr)
			continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
