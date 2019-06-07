
#include "InGameSession.h"
#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"

#define print(text, ...)	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(text), ##__VA_ARGS__), false); \
											UE_LOG(LogTemp, Warning, TEXT(text), ##__VA_ARGS__); }

AInGameSession::AInGameSession(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	print("Net mode is %d", GetNetMode())
}

void AInGameSession::RegisterServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Registering server"));
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();
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

	Sessions->AddOnCreateSessionCompleteDelegate_Handle(FOnCreateSessionCompleteDelegate::CreateUObject(this, &AInGameSession::OnCreateSessionComplete));
	FOnlineSessionSettings Settings;
	Settings.NumPublicConnections = 50;
	Settings.bIsLANMatch = true;
	//Settings.bAllowJoinInProgress = true;
	Settings.bIsDedicated = true;
	Settings.bUsesPresence = false;
	Settings.bAllowJoinViaPresence = false;

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