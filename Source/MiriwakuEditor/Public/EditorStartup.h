// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
struct FButton
{
	FString Text;
	FString Tooltip;
	FSimpleDelegate OnClick;
	bool bCloseOnClick = true;
};
struct FNotification
{
	uint64 UniqueId = 0;
	FString Message;
	FSimpleDelegate OnClose;
	float Duration = 10.f;

	TArray<FButton> Buttons;
};

class MIRIWAKUEDITOR_API EditorStartup
{
public:
	EditorStartup();
	~EditorStartup();

	static void ShowPopup();
	static void OpenLink(const FString& Url);
private:

	static void ShowNotification(const FNotification& notification);
	//void AddButton(FNotificationInfo& Info, const FSimpleDelegate& OnClick, const FText& Text, const FText& Tooltip, bool bCloseOnClick, const TSharedRef<TWeakPtr<SNotificationItem>>& PtrToPtr);
};
