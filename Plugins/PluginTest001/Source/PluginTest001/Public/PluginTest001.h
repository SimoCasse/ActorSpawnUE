// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class PLUGINTEST001_API FPluginTest001Module : public IModuleInterface, public FSelfRegisteringExec
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static FString GetHelloWorld();
	bool Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar) override;

protected:
	void* AivHandle = nullptr;
	//TWeakPtr<FAivSomething> SomethingPtr;
};
