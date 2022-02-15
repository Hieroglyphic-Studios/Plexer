
#include "Math/UnrealMathUtility.h"
#include "Math/Rotator.h"

#include "PlexerUtils.h"



// Procedural fps animations for mouse X input
void Plexer::FPSTurnInterp(UStaticMeshComponent* Object, UCameraComponent* Camera, float InterpSpeed, float InputAxisMultiplier, float InputAxis)
{
	FRotator Rotation = Object->GetComponentRotation();

	// Interpolate weapon 'Roll' rotation to calculated rotation
	float Roll = FMath::InterpExpoInOut(Rotation.Roll, ((InputAxis * -1) * InputAxisMultiplier), InterpSpeed);
	Object->SetWorldRotation(FRotator(Rotation.Pitch, (Camera->GetComponentRotation().Yaw + 180), Roll));
}

// Procedural fps animations for mouse Y input
void Plexer::FPSLookInterp(UStaticMeshComponent* Object, UCameraComponent* Camera, float InterpSpeed, float InputAxisMultiplier, float InputAxis)
{
	FRotator Rotation = Object->GetComponentRotation();

	// Interpolate weapon 'Pitch' rotation to calculated rotation
	float Pitch = FMath::InterpExpoInOut(Rotation.Pitch, ((InputAxis * InputAxisMultiplier) + Rotation.Pitch), InterpSpeed);
	Object->SetWorldRotation(FRotator(Pitch, Rotation.Yaw, Rotation.Roll));

	Pitch = FMath::InterpExpoInOut(((InputAxis * InputAxisMultiplier) + Rotation.Pitch), (Camera->GetComponentRotation().Pitch * -1), InterpSpeed);
	Object->SetWorldRotation(FRotator(Pitch, Rotation.Yaw, Rotation.Roll));
}

