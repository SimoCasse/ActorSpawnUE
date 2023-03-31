// Copyright Epic Games, Inc. All Rights Reserved.

#include "PluginTest001.h"
#include "UselessObject.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include <vector>

#define LOCTEXT_NAMESPACE "FPluginTest001Module"
/*
extern "C"
{
   typedef const char* (*aiv_get_string_t)();
   typedef int (*aiv_adder_t)(const int a, const int b);
}
*/
/*
struct FAivSomething
{
   FString Name;
   int32 value;
   
   void Hello()
   {

   }
};


void Dummy(TWeakPtr<FAivSomething> SomethingPtr)
{
	if (SomethingPtr.IsValid())
	{
	SomethingPtr.Pin()->Hello();
	}
}
*/

void FPluginTest001Module::StartupModule()
{
	/*
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	TArray<FAssetData> AssetsData;
	AssetRegistryModule.Get().GetAllAssets(AssetsData);

	for (const FAssetData& AssetData : AssetsData)
	{
		UE_LOG(LogTemp, Error, TEXT("Assets %s: %s"), *AssetData.AssetClass.ToString());
	}
	*/

	/*
	UUselessObject* UselessObject = NewObject<UUselessObject>();
	UE_LOG(LogTemp, Warning, TEXT("Useless: %s %s %s"), *UselessObject->GetName(),*UselessObject->GetPathName(),*UselessObject->GetFullName());

	UselessObject->DummyNumber = 100;

	UClass* UselessClass = UUselessObject::StaticClass();
	FProperty* DummyNumberProperty = UselessClass->FindPropertyByName(TEXT("DummyNumber"));

	UE_LOG(LogTemp, Error, TEXT("DummyNumberProperty at %p"), DummyNumberProperty);
 */

	/*
	FIntProperty* IntProperty = new FIntProperty(UselessClass,
		TEXT("DummyNumber"),
		RF_MarkAsNative | RF_Public | RF_Standalone | RF_Transient,
		STRUCT_OFFSET(UUselessObject, DummyNumber),
		CPF_Edit | CPF_BlueprintVisible);

	UselessClass->StaticLink(false);
	*/

	/*
	DummyNumberProperty = UselessClass->FindPropertyByName(TEXT("DummyNumber"));

	UE_LOG(LogTemp, Error, TEXT("DummyNumberProperty at %p"), DummyNumberProperty);
	*/
}

	/*
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	{
	     TSharedRef<FAivSomething> SomethingPtr = MakeShared<FAivSomething>();
		 //SomethingPtr = nullptr;
		 Dummy(SomethingPtr);

		 TWeakPtr<FAivSomething> IAmWeak = TWeakPtr<FAivSomething>(SomethingPtr);
	}
	//SomethingPtr->Name;

	AivHandle = FPlatformProcess::GetDllHandle(TEXT("C:/Users/simon/Aiv_Code_3/libaiv.dll"));
	
	if (!AivHandle)
	{
		return;
	}

	aiv_get_string_t aiv_get_string = reinterpret_cast<aiv_get_string_t>(FPlatformProcess::GetDllExport(AivHandle, TEXT("aiv_get_string")));
	if (!aiv_get_string)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
		return;
	}
	aiv_adder_t aiv_adder = reinterpret_cast<aiv_adder_t>(FPlatformProcess::GetDllExport(AivHandle, TEXT("aiv_adder")));
	if (!aiv_adder)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
		return;
	}


	UE_LOG(LogTemp, Error, TEXT("Message from aiv: %s %d"), UTF8_TO_TCHAR(aiv_get_string()), aiv_adder(100, 200));
	*/
bool FPluginTest001Module::Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("Aivprops")))
	{
		TArray<FAssetData>AssetsData;
		GEditor->GetContentBrowserSelections(AssetsData);

		for (const FAssetData& AssetData:AssetsData)
		{
			UObject* Instance = AssetData.GetAsset();
			UClass* AssetClass = Instance->GetClass();
			for (TFieldIterator<FProperty> It(AssetClass); It; ++It)
			{
				FProperty* Property = *It;
				
				    if(FStrProperty* StrProperty = CastField<FStrProperty>(Property))
					{
						const FString& String = StrProperty->GetPropertyValue_InContainer(Instance);
						UE_LOG(LogTemp, Error, TEXT("Asset %s, Props %s, Value %s"), *Instance->GetPathName(), *Property->GetName(), *String);

					}
			}
		}

		return true;
	}


	if (FParse::Command(&Cmd, TEXT("Aivworlds")))
	{
		for (TObjectIterator<UWorld> It; It; ++It)
		{
		    UWorld* World = *It;
			UE_LOG(LogTemp, Warning, TEXT("Found world %s"), *World->GetFullName());

			if (World -> WorldType == EWorldType::Editor)
			{
				UE_LOG(LogTemp, Error, TEXT("I am the editor"));
				World->SpawnActor<AActor>(FVector(0, 0, 300), FRotator());
			}
		}
		return true;
	}

	if (FParse::Command(&Cmd, TEXT("Aivassets")))
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

		TArray<FAssetData> AssetsData;
		AssetRegistryModule.Get().GetAllAssets(AssetsData);

		for (const FAssetData& AssetData : AssetsData)
		{
			Ar.Logf(TEXT("Assets %s: %d"), *AssetData.GetFullName(), AssetData.IsAssetLoaded());
		}
		
		AssetsData.Empty();
		AssetRegistryModule.Get().GetAssetsByClass(*UMaterial::StaticClass()->GetPathName(),AssetsData);

		for (const FAssetData& AssetData : AssetsData)
		{
			UE_LOG(LogTemp,Error,TEXT("Assets %s: %d"), *AssetData.GetFullName(), AssetData.IsAssetLoaded());
		}

	}
	return false;
}

void FPluginTest001Module::ShutdownModule()
{
	/*
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (AivHandle)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
	}
	*/
}

 FString FPluginTest001Module::GetHelloWorld()
{
	return TEXT("Hello!!!");
}
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPluginTest001Module, PluginTest001)