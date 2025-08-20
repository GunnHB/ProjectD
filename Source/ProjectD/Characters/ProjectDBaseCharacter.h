// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemInterface.h"

#include "ProjectDBaseCharacter.generated.h"

class UDataAsset_StartUpDataBase;

class UProjectDAttributeSet;
class UProjectDAbilitySystemComponent;

UCLASS()
class PROJECTD_API AProjectDBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AProjectDBaseCharacter();

	// ~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// ~ End IAbilitySystemInterface Interface

protected:
	// ~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// ~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	TObjectPtr<UProjectDAbilitySystemComponent> ProjectDAbilitySystemComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	TObjectPtr<UProjectDAttributeSet> ProjectDAttributeSet = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData = nullptr;

public:
	FORCEINLINE UProjectDAbilitySystemComponent* GetProjectDAbilitySystemComponent() const { return ProjectDAbilitySystemComponent; }
	FORCEINLINE UProjectDAttributeSet* GetProjectDAttributeSet() const { return ProjectDAttributeSet; }
};
