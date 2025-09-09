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
	
	FFootIKInfo FootTrace(const FName& SocketName);
	
	void UpdateFootOffset(float DeltaTime, float TargetValue, float* EffectorValue, float InterpSpeed);
	void UpdateFootRotation(float DeltaTime, const FRotator& TargetValue, FRotator* FootRotatorValue, float InterpSpeed);
	FRotator NormalToRotator(const FVector& Vector);

private:
	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	FName LeftFootSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	FName RightFootSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FootIK|Settings", meta = (AllowPrivateAccess = "true"))
	float TraceDistance = 0.f;

	UPROPERTY(BlueprintReadOnly, Category="FootIK", meta=(AllowPrivateAccess="true"))
	FRotator LeftFootRotation = FRotator::ZeroRotator;
	
	UPROPERTY(BlueprintReadOnly, Category="FootIK", meta=(AllowPrivateAccess="true"))
	FRotator RightFootRotation = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category="FootIK", meta=(AllowPrivateAccess="true"))
	float LeftOffset = 0.f;

	UPROPERTY(BlueprintReadOnly, Category="FootIK", meta=(AllowPrivateAccess="true"))
	float RightOffset = 0.f;

	UPROPERTY(BlueprintReadOnly, Category="FootIK", meta=(AllowPrivateAccess="true"))
	float PelvisOffset = 0.f;
	
public:
	FORCEINLINE float GetLeftOffset() const {return LeftOffset;}
	FORCEINLINE float GetRightOffset() const {return RightOffset;}
	FORCEINLINE float GetPelvisOffset() const {return PelvisOffset;}
	FORCEINLINE FRotator GetLeftFootRotation() const {return LeftFootRotation;}
	FORCEINLINE FRotator GetRightFootRotation() const {return RightFootRotation;}
};
