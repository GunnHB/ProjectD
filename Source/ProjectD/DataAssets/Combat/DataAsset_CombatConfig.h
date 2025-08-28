// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_CombatConfig.generated.h"

class UComboNode;
/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTD_API UDataAsset_CombatConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced)
	TObjectPtr<UComboNode> RootNode = nullptr;
};
