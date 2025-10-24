#pragma once

#include "Misc/MessageDialog.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

namespace DebugHeader
{
	static void Print(const FString& Message, const FColor& Color)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, Color, Message);
		}
	}

	static void PrintLog(const FString& Message)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	}

	static EAppReturnType::Type ShowMessageDialogue(const EAppMsgType::Type MsgType, const FString& Message, const bool bShowMsgAsWarning = true)
	{
		if (bShowMsgAsWarning)
		{
			const FText MsgTitle = FText::FromString("Warning");
			return FMessageDialog::Open(MsgType, FText::FromString(Message), MsgTitle);
		}
		else
		{
			const FText MsgTitle = FText::FromString("Info");
			return FMessageDialog::Open(MsgType, FText::FromString(Message), MsgTitle);
		}
	}

	static void ShowNotifyInfo(const FString& Message)
	{
		FNotificationInfo NotifyInfo(FText::FromString(Message));
		NotifyInfo.bUseLargeFont = true;
		NotifyInfo.FadeOutDuration = 5.0f;

		FSlateNotificationManager::Get().AddNotification(NotifyInfo);
	}
}