#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlexerGameModeBase.generated.h"

UCLASS()
class PLEXER_API APlexerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APlexerGameModeBase();
	virtual ~APlexerGameModeBase() = default;
	
};
