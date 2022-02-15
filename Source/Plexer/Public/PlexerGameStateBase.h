#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlexerGameStateBase.generated.h"

UCLASS()
class PLEXER_API APlexerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	APlexerGameStateBase();
	virtual ~APlexerGameStateBase() = default;
	
};
