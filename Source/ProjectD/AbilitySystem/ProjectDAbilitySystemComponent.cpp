// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDAbilitySystemComponent.h"

void UProjectDAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (InInputTag.IsValid() == false)
		return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag) == false)
			continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UProjectDAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
