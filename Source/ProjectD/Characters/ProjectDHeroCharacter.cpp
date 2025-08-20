// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDHeroCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "ProjectD/DevHelper.h"
#include "ProjectD/ProjectDGameplayTags.h"
#include "ProjectD/AbilitySystem/ProjectDAbilitySystemComponent.h"
#include "ProjectD/AbilitySystem/ProjectDAttributeSet.h"
#include "ProjectD/Components/Input/ProjectDInputComponent.h"

#include "ProjectD/DataAssets/Input/DataAsset_InputConfig.h"
#include "ProjectD/DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

AProjectDHeroCharacter::AProjectDHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 275.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void AProjectDHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	checkf(InputConfigDataAsset, TEXT("forgot to assign a valid data asset as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UProjectDInputComponent* ProjectDInputComponent = CastChecked<UProjectDInputComponent>(PlayerInputComponent);

	ProjectDInputComponent->BindNativeInputAction(InputConfigDataAsset, ProjectDGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	ProjectDInputComponent->BindNativeInputAction(InputConfigDataAsset, ProjectDGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AProjectDHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CharacterStartUpData.IsNull() == false)
	{
		UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous();
		if (IsValid(LoadedData))
			LoadedData->GiveToAbilitySystemComponent(ProjectDAbilitySystemComponent);
	}
}

void AProjectDHeroCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AProjectDHeroCharacter::Input_Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
		AddControllerYawInput(LookAxisVector.X);

	if (LookAxisVector.Y != 0.f)
		AddControllerPitchInput(LookAxisVector.Y);
}
