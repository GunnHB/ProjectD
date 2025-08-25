// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectD/ProjectDStructTypes.h"
#include "ProjectD/Components/PawnExtensionComponentBase.h"

#include "PawnCombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTD_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Combat")
	FCombatData CombatData;

	UPROPERTY(BlueprintReadWrite, Category="Character|Combat")
	FGameplayTag CombatStatusTag;

public:
	FORCEINLINE FCombatData GetCombatData() const { return CombatData; }
};
