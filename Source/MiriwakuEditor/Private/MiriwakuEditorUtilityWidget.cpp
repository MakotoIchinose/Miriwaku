// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG


#include "MiriwakuEditorUtilityWidget.h"

#define DEBUG_MSG(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT(x), __VA_ARGS__));}

UMiriwakuEditorUtilityWidget::UMiriwakuEditorUtilityWidget()
{

}

UMiriwakuEditorUtilityWidget::~UMiriwakuEditorUtilityWidget()
{

}

void UMiriwakuEditorUtilityWidget::ModuleTest()
{
	DEBUG_MSG("This is Million Framework.");
}