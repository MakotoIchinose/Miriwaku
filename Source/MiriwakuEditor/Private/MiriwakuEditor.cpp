// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

#include "MiriwakuEditor.h"
#include "Modules/ModuleManager.h"

#include "EditorStartup.h"

#define LOCTEXT_NAMESPACE "FMiriwakuEditor"

void FMiriwakuEditor::StartupModule()
{
	EditorStartup::ShowPopup();
}

void FMiriwakuEditor::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMiriwakuEditor, MiriwakuEditor);