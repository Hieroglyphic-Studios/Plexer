#include "PlexerGameModeBase.h"
#include "PlexerGameStateBase.h"
#include "PlexerCharacter.h"

APlexerGameModeBase::APlexerGameModeBase()
{
	GameStateClass = APlexerGameStateBase::StaticClass();
	DefaultPawnClass = APlexerCharacter::StaticClass();
}
