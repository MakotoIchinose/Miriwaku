// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class FMiriwakuEditor : public IModuleInterface
{
public:
	// Begin IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// End IModuleInterface implementation
};

