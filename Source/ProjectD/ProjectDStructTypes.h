
#pragma once

#include "GameplayTagContainer.h"

#include "ProjectDStructTypes.generated.h"

class UProjectDHeroGameplayAbility;

USTRUCT(BlueprintType)
struct FProjectDHeroAbilitySets
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UProjectDHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};
