// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectD/AnimInstances/ProjectDBaseAnimInstance.h"

#include "ProjectDHeroLinkedAnimInstance.generated.h"

class UProjectDHeroAnimInstance;
/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDHeroLinkedAnimInstance : public UProjectDBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	UProjectDHeroAnimInstance* GetHeroAnimInstance() const;
};
