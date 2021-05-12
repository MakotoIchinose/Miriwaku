// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG


#include "EditorStartup.h"
#include "Misc/MessageDialog.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

EditorStartup::EditorStartup()
{
}

EditorStartup::~EditorStartup()
{
}

inline void AddButton(
	FNotificationInfo& Info,
	const FSimpleDelegate& OnClick,
	const FText& Text,
	const FText& Tooltip,
	bool bCloseOnClick,
	const TSharedRef<TWeakPtr<SNotificationItem>>& PtrToPtr)
{
	const auto Callback = FSimpleDelegate::CreateLambda([=]()
		{
			OnClick.ExecuteIfBound();

			if (bCloseOnClick)
			{
				auto Ptr = PtrToPtr->Pin();
				if (Ptr.IsValid())
				{
					Ptr->SetFadeOutDuration(0);
					Ptr->Fadeout();
				}
			}
		});

	Info.ButtonDetails.Add(FNotificationButtonInfo(
		Text,
		Tooltip,
		Callback,
		SNotificationItem::CS_None));
}

void EditorStartup::ShowPopup()
{

	FNotification Notification;
	Notification.Message = "Welcome to Million Framework Editor!";
	Notification.Duration = 1e6f;

	auto& Button = Notification.Buttons.Emplace_GetRef();
	Button.Text = "GitHub";
	Button.Tooltip = "The GitHub repository. Contribute or file issues you're facing with Million Framwork.";
	Button.bCloseOnClick = false;
	Button.OnClick = FSimpleDelegate::CreateLambda([=]()
		{
			EditorStartup::OpenLink("https://github.com/TheHoodieGuy02/Miriwaku");
		});



	auto& Button2 = Notification.Buttons.Emplace_GetRef();
	Button2.Text = "Discord";
	Button2.Tooltip = "Open the Discord server.";
	Button2.bCloseOnClick = false;
	Button2.OnClick = FSimpleDelegate::CreateLambda([=]()
		{
			EditorStartup::OpenLink("https://discord.gg/xgvqQwmPkP");
		});

	auto& Button3 = Notification.Buttons.Emplace_GetRef();
	Button3.Text = "Documentation";
	Button3.Tooltip = "Coming soon!";
	Button3.bCloseOnClick = false;
	Button3.OnClick = FSimpleDelegate::CreateLambda([=]()
		{
			EditorStartup::OpenLink("https://github.com/TheHoodieGuy02/Miriwaku/wiki");
		});

	auto& Button4 = Notification.Buttons.Emplace_GetRef();
	Button4.Text = "Patreon";
	Button4.Tooltip = "Support this project as little as a dollar a month!";
	Button4.bCloseOnClick = false;
	Button4.OnClick = FSimpleDelegate::CreateLambda([=]()
		{
			EditorStartup::OpenLink("https://patreon.com/TheHoodieGuy02");
		});
}

void EditorStartup::OpenLink(const FString& Url)
{
	FString Error;
	FPlatformProcess::LaunchURL(*Url, nullptr, &Error);
	if (!Error.IsEmpty())
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Failed to open " + Url + "\n:" + Error));
	}
}

void EditorStartup::ShowNotification(const FNotification& Notification)
{

	FNotificationInfo Info(FText::FromString(Notification.Message));
	Info.CheckBoxState = ECheckBoxState::Unchecked;
	Info.ExpireDuration = Notification.Duration;

	const TSharedRef<TWeakPtr<SNotificationItem>> PtrToPtr = MakeShared<TWeakPtr<SNotificationItem>>();

	for (auto& Button : Notification.Buttons)
	{
		AddButton(Info, Button.OnClick, FText::FromString(Button.Text), FText::FromString(Button.Tooltip), Button.bCloseOnClick, PtrToPtr);
	}
	AddButton(Info, Notification.OnClose, FText::FromString("Close"), FText::FromString("Close"), true, PtrToPtr);

	const auto Ptr = FSlateNotificationManager::Get().AddNotification(Info);
	*PtrToPtr = Ptr;
}
