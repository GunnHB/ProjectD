// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ProjectDBaseCharacter.h"
#include "ProjectDHeroCharacter.generated.h"

class UHeroCombatComponent;
struct FInputActionValue;

class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class PROJECTD_API AProjectDHeroCharacter : public AProjectDBaseCharacter
{
	GENERATED_BODY()

public:
	AProjectDHeroCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	// ~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// ~ End APawn Interface

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> CameraBoom = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> FollowCamera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent = nullptr;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset = nullptr;

	void Input_Move(const FInputActionValue& Value);
	void Input_Look(const FInputActionValue& Value);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
