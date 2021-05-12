// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "MiriwakuEditorUtilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class MIRIWAKUEDITOR_API UMiriwakuEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:
	UMiriwakuEditorUtilityWidget();
	~UMiriwakuEditorUtilityWidget();

	UFUNCTION(BlueprintCallable)
		void ModuleTest();
};
