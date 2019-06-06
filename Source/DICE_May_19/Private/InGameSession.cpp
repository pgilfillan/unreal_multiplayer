
#include "InGameSession.h"
#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"

void AInGameSession::RegisterServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Registering server"));
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get(FName("Null"));
	if (!OnlineSub)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get OSS"));
		return;
	}

	IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
	if (!Sessions)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get Sessions interface"));
		return;
	}

	Sessions->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);

	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &AInGameSession::OnCreateSessionComplete);
	FOnlineSessionSettings Settings;

	UE_LOG(LogTemp, Warning, TEXT("Creating session"));
	Sessions->CreateSession(0, NAME_GameSession, Settings);
}

void AInGameSession::OnCreateSessionComplete(FName Session, bool Created)
{
	if (Created)
	{
		UE_LOG(LogTemp, Warning, TEXT("Session created"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create session"));
	}
}