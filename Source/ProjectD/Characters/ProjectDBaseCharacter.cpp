// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDBaseCharacter.h"

AProjectDBaseCharacter::AProjectDBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}
