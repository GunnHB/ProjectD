// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDHeroAnimInstance.h"

#include "ProjectD/Characters/ProjectDBaseCharacter.h"
#include "ProjectD/Characters/ProjectDHeroCharacter.h"

void UProjectDHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (IsValid(OwningCharacter))
		OwningHeroCharacter = Cast<AProjectDHeroCharacter>(OwningCharacter);
}
