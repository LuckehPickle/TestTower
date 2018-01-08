// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"


// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create camera component
    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));

    // Adjust position of camera
    FirstPersonCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

    FirstPersonCameraComponent->bUsePawnControlRotation = true;

    // Attach the camera to our capsule
    FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Now using FirstPersonCharacter"));
    }
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Setup movement bindings
    PlayerInputComponent->BindAxis("MoveX", this, &AFirstPersonCharacter::MoveX);
    PlayerInputComponent->BindAxis("MoveY", this, &AFirstPersonCharacter::MoveY);

    // Setup camera bindings
    PlayerInputComponent->BindAxis("Yaw", this, &AFirstPersonCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("Pitch", this, &AFirstPersonCharacter::AddControllerPitchInput);

    // Setup "action" bindings
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFirstPersonCharacter::StopJump);

}

void AFirstPersonCharacter::MoveX(float AxisValue)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, AxisValue);
}

void AFirstPersonCharacter::MoveY(float AxisValue)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, AxisValue);
}

void AFirstPersonCharacter::StartJump()
{
    bPressedJump = true;
}

void AFirstPersonCharacter::StopJump()
{
    bPressedJump = false;
}