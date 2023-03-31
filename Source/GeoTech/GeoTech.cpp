// Copyright Epic Games, Inc. All Rights Reserved.

#include "GeoTech.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"
#include "Dummy003.h"
#include "PluginTest001.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Editor.h"
#include "DummyActor.h"

DEFINE_LOG_CATEGORY(LogAIV);

bool operator<(const FModuleStatus& ModuleA,const FModuleStatus& ModuleB)
{
	return ModuleA.Name < ModuleB.Name;
}

class FAIVGamemodule : public FDefaultGameModuleImpl, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override
	{
		UE_LOG(LogAIV, Error, TEXT("Hello Aiv"));

		FModuleManager::LoadModuleChecked<FPluginTest001Module>("PluginTest001");
		//FPluginTest001Module::GetHelloWorld();
		FDummy003Module::HelloWorld();
		//PublicAdditionalLibraries.Add("D:/libaiv.lib");

		/*
		FString Message = TEXT("Hello水Test水");

		FFileHelper::SaveStringToFile(Message, TEXT("C:/XboxGames/simplestring.txt"));
		*/
		/*
		TArray<FModuleStatus> Modulestatuses;
		FModuleManager::Get().QueryModules(Modulestatuses);

		Modulestatuses.Sort();
		TArray<int32, TInlineAllocator<5>> Hello;
		Hello.Add(1);

		//FString Hello = "Hello";  stringa modo 1
		//FString Hello = TEXT("Hello"); stringa modo 2 aiuta il parser in caso di caratteri unicode

		
		for (const FModuleStatus& ModuleStatus:Modulestatuses)
		{
			UE_LOG(LogTemp, Error, TEXT("Module: %s %s"),*ModuleStatus.FilePath, *ModuleStatus.Name);
		}
		
		UE_LOG(LogTemp, Warning, TEXT("Hello World from aiv module"));
		*/
	}
	virtual void ShutdownModule() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Goodbye World from aiv module"));
	}
	virtual bool Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
	{

		if (FParse:: Command(&Cmd, TEXT("foobar")))
		{
		  TArray<FModuleStatus> Modulestatuses;
		  FModuleManager::Get().QueryModules(Modulestatuses);

		  Modulestatuses.Sort();
		  
		  for (const FModuleStatus& ModuleStatus : Modulestatuses)
		  {
			  if (ModuleStatus.Name.StartsWith(Cmd))
			  {
		        Ar.Logf(TEXT("Module: %s %s"), *ModuleStatus.FilePath, *ModuleStatus.Name);
			  }
		  }
		 
			return true;
		}
		
		else if (FParse::Command(&Cmd, TEXT("NewSpawn")))
		{
			if (FParse::Command(&Cmd, TEXT("BluePrints")))
			{
				TArray<FAssetData>AssetsData;
				GEditor->GetContentBrowserSelections(AssetsData);
				for (const FAssetData& AssetData : AssetsData)
				{
					UObject* NewInstance = AssetData.GetAsset();
					UClass* AssetClass = NewInstance->GetClass();
					if (AssetClass->IsChildOf(UBlueprint::StaticClass()))
					{
						AssetClass = Cast<UBlueprint>(NewInstance)->GeneratedClass;
						if (AssetClass->IsChildOf(AActor::StaticClass()))
						{
							UWorld* World = GEditor->GetEditorWorldContext().World();
							World->SpawnActor(AssetClass);
							World->SpawnActor(AssetClass);
							World->SpawnActor(AssetClass);
							UE_LOG(LogTemp, Error, TEXT("Currently spawning 3 new actors in the World"));
						}
					}
				}
				return true;
			}
		}
		return false;
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FAIVGamemodule, GeoTech, "GeoTech" );
