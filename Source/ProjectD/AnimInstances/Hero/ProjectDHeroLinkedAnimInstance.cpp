// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDHeroLinkedAnimInstance.h"

#include "ProjectDHeroAnimInstance.h"

UProjectDHeroAnimInstance* UProjectDHeroLinkedAnimInstance::GetHeroAnimInstance() const
{
	return Cast<UProjectDHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
