// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectD/ProjectDStructTypes.h"
#include "ProjectD/Components/PawnExtensionComponentBase.h"
#include "ProjectDFootIKComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTD_API UProjectDFootIKComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UProjectDFootIKComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
	
	void TraceFoot(const FName& SocketName, FFootIKData& OutFootIKData, float& OutOffset);

private:
	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	FName LeftFootSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	FName RightFootSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	float TraceDistance = 0.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FootIK|State", meta = (AllowPrivateAccess = "true"))
	FFootIKData LeftFootIKData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FootIK|State", meta = (AllowPrivateAccess = "true"))
	FFootIKData RightFootIKData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FootIK|State", meta = (AllowPrivateAccess = "true"))
	float PelvisOffset = 0.f;

public:
	FORCEINLINE const FFootIKData& GetLeftFootIKData() const { return LeftFootIKData; }
	FORCEINLINE const FFootIKData& GetRightFootIKData() const { return RightFootIKData; }
	FORCEINLINE float GetPelvisOffset() const { return PelvisOffset; }
};
