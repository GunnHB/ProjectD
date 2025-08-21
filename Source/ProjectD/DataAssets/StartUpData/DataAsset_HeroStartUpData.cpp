// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_HeroStartUpData.h"

#include "ProjectD/AbilitySystem/ProjectDAbilitySystemComponent.h"
#include "ProjectD/AbilitySystem/Abilities/ProjectDHeroGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UProjectDAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FProjectDHeroAbilitySets& AbilitySet : HeroStartUpAbilitySets)
	{
		if (AbilitySet.IsValid() == false)
			continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
