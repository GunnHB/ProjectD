// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "ProjectD/DataAssets/Input/DataAsset_InputConfig.h"
#include "ProjectDInputComponent.generated.h"

class UDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<typename UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template <typename UserObject, typename CallbackFunc>
void UProjectDInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("input config data asset is null. can not proceed with binding"));

	UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag);
	if (IsValid(FoundAction))
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
}
