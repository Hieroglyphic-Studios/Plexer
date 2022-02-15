
#include "PlexerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"

#include "PlexerUtils.h"



// Sets default values
APlexerCharacter::APlexerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
	Camera->SetRelativeLocation(FVector(0, 0, 50));

	// Setup weapon
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(Camera);
	Weapon->SetRelativeLocation(FVector(60, 16, -13));
	Weapon->SetRelativeRotation(FRotator(0, 180, 0));
	Weapon->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));
}

// Called when the game starts or when spawned
void APlexerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlexerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlexerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement input
	PlayerInputComponent->BindAxis(TEXT("Walk"), this, &APlexerCharacter::Walk);
	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &APlexerCharacter::Strafe);

	// Mouse input
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlexerCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("Look"), this, &APlexerCharacter::Look);

	// Jumping input
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlexerCharacter::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &APlexerCharacter::EndJump);
}

// Turning right and left (mouse input) with procedural weapon animations
void APlexerCharacter::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
	Plexer::FPSTurnInterp(Weapon, Camera, WeaponXInterpSpeed, WeaponXRotationIntensity, AxisValue);

}

// Looking up and down (mouse input) with procedural weapon animations
void APlexerCharacter::Look(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
	Plexer::FPSLookInterp(Weapon, Camera, WeaponYInterpSpeed, WeaponYRotationIntensity, AxisValue);
}

// Movement for forward and backward
void APlexerCharacter::Walk(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

// Movement for left and right
void APlexerCharacter::Strafe(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

// Jumping
void APlexerCharacter::StartJump()
{
	bPressedJump = true;
}

void APlexerCharacter::EndJump()
{
	bPressedJump = false;
}
