// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectD/Components/PawnExtensionComponentBase.h"
#include "ParkourComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTD_API UParkourComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UParkourComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void TraceAndDetect();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Parkour")
	float TraceDistance = 0.f;

	FHitResult TraceHitResult;
};
