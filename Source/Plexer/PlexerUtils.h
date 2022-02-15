
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"

// Print messege on screen
#define Print(Text)\
	if (GEngine)\
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, Text)

// Print messege on screen with key specifier
#define PrintKey(Key, Text)\
	if (GEngine)\
		GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::White, Text)



// Namespace for utility functions and data
namespace Plexer
{
	void FPSTurnInterp(UStaticMeshComponent* Object, UCameraComponent* Camera, float InterpSpeed, float InputAxisMultiplier, float InputAxis);

	void FPSLookInterp(UStaticMeshComponent* Object, UCameraComponent* Camera, float InterpSpeed, float InputAxisMultiplier, float InputAxis);
};

