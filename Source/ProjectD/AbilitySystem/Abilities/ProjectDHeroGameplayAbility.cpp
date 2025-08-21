// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDHeroGameplayAbility.h"

#include "ProjectD/Characters/ProjectDHeroCharacter.h"
#include "ProjectD/Controllers/ProjectDHeroController.h"

AProjectDHeroCharacter* UProjectDHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (CachedHeroCharacter.IsValid() == false)
		CachedHeroCharacter = Cast<AProjectDHeroCharacter>(CurrentActorInfo->AvatarActor);

	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

AProjectDHeroController* UProjectDHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (CachedHeroController.IsValid() == false)
		CachedHeroController = Cast<AProjectDHeroController>(CurrentActorInfo->PlayerController);

	return CachedHeroController.IsValid() ? CachedHeroController.Get() : nullptr;
}

UHeroCombatComponent* UProjectDHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
