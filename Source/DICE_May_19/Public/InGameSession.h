#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "OnlineSessionInterface.h"
#include "InGameSession.generated.h"

/**
 * 
 */
UCLASS()
class DICE_MAY_19_API AInGameSession : public AGameSession
{
	GENERATED_BODY()

	void RegisterServer() override;
	AInGameSession(const FObjectInitializer& ObjectInitializer);

private:
	void OnCreateSessionComplete(FName Session, bool Created);
};
