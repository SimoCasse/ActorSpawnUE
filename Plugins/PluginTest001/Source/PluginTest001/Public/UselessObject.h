// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UselessObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType) 
class PLUGINTEST001_API UUselessObject : public UObject
{
	GENERATED_BODY()
	
public:
	UUselessObject();
	~UUselessObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DummyNumber;

	UFUNCTION(BlueprintCallable)
		int32 GetNumber(const FString& value);
};
