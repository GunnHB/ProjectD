
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ComboNode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UComboNode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	TObjectPtr<UAnimMontage> AnimMontage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(DisplayName="Next Combo Nodes"), Instanced)
	TMap<FGameplayTag, UComboNode*> NextComboNodes;
};