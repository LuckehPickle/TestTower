// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class TESTTOWER_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles movement along the X axis
	UFUNCTION() 
	void MoveX(float AxisValue);

	// Handles movement along the Y axis
	UFUNCTION()
	void MoveY(float AxisValue);

    // Sets the jump flag when the key is pressed
    UFUNCTION()
    void StartJump();

    // Clears the jump flag when the key is released
    UFUNCTION()
    void StopJump();

    UFUNCTION()
    void StartSprint();

    UFUNCTION()
    void StopSprint();

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FirstPersonCameraComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    USkeletalMeshComponent* FirstPersonMesh;

private:
    float DefaultMaxWalkSpeed;
    float SprintModifier = 2.0f;
	
};
