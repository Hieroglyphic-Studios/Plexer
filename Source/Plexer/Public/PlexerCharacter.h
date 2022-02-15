
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlexerCharacter.generated.h"



UCLASS()
class PLEXER_API APlexerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlexerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void Turn(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void Look(float AxisValue);

	// Movement
	UFUNCTION(BlueprintCallable)
	void Walk(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void Strafe(float AxisValue);

	// Jumping
	UFUNCTION(BlueprintCallable)
	void StartJump();

	UFUNCTION(BlueprintCallable)
	void EndJump();

	// Character Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Weapon;

	// "APlexerCharacter" properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponXInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponXRotationIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponYInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponYRotationIntensity;

};
