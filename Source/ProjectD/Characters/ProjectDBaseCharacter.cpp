// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDBaseCharacter.h"

#include "ProjectD/AbilitySystem/ProjectDAbilitySystemComponent.h"
#include "ProjectD/AbilitySystem/ProjectDAttributeSet.h"

#include "ProjectD/DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

AProjectDBaseCharacter::AProjectDBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ProjectDAbilitySystemComponent = CreateDefaultSubobject<UProjectDAbilitySystemComponent>(TEXT("ProjectDAbilitySystemComponent"));
	ProjectDAttributeSet = CreateDefaultSubobject<UProjectDAttributeSet>(TEXT("ProjectDAttributeSet"));
}

UAbilitySystemComponent* AProjectDBaseCharacter::GetAbilitySystemComponent() const
{
	return GetProjectDAbilitySystemComponent();
}

void AProjectDBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsValid(ProjectDAbilitySystemComponent))
	{
		ProjectDAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(CharacterStartUpData.IsNull() == false, TEXT("forgot to assign start up data to %s"), *GetName());
	}
}
