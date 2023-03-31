// Fill out your copyright notice in the Description page of Project Settings.


#include "UselessObject.h"

UUselessObject::UUselessObject()
{
	UE_LOG(LogTemp, Error, TEXT("Hello I am UselessOBject at %p"), this);
}
UUselessObject::~UUselessObject()
{
	UE_LOG(LogTemp, Error, TEXT("Goodbye I am UselessOBject at %p"), this);
}
int32 UUselessObject::GetNumber(const FString& value)
{
	return value.Len();
}