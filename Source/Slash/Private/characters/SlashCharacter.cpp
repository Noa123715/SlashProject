#include "characters/SlashCharacter.h"

ASlashCharacter::ASlashCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
}
void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASlashCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void ASlashCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASlashCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &ASlashCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASlashCharacter::LookUp);
}

