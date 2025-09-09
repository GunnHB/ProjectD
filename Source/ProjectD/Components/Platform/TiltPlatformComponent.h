// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TiltPlatformComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTD_API UTiltPlatformComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTiltPlatformComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere)
	float MaxPitch = 0.f;

	UPROPERTY(EditAnywhere)
	bool bReverse = false;
	
	float CurrentPitch = 0.f;
};
