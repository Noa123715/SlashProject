#include "characters/SlashCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASlashCharacter::ASlashCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->SetupAttachment(GetRootComponent());
	CameraArm->TargetArmLength = 200.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraArm);
}
void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASlashCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0, ControlRotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASlashCharacter::MoveSideways(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0, ControlRotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
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
	PlayerInputComponent->BindAxis("MoveSideways", this, &ASlashCharacter::MoveSideways);
	PlayerInputComponent->BindAxis("Turn", this, &ASlashCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASlashCharacter::LookUp);
}

