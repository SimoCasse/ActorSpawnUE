// Fill out your copyright notice in the Description page of Project Settings.


#include "StupidFactory.h"
#include "ImageUtils.h"

UStupidFactory::UStupidFactory()
{
	bEditorImport = true;
	SupportedClass = UTexture2D::StaticClass();
    Formats.Add("foo;Foo Stupid Format*");
}

UObject* UStupidFactory::FactoryCreateFile
(
    UClass * InClass,
    UObject* InParent,
    FName InName,
    EObjectFlags Flags,
    const FString & Filename,
    const TCHAR * Parms,
    FFeedbackContext * Warn,
    bool& bOutOperationCanceled 
)

{
    UE_LOG(LogTemp, Error, TEXT("Filename: %s"), *Filename);
    FCreateTexture2DParameters Params;
    TArray<FColor>Pixels;
    Pixels.AddZeroed(1024 * 1024);
    return FImageUtils::CreateTexture2D(1024, 1024, Pixels, InParent, InName.ToString(), Flags, Params);
}