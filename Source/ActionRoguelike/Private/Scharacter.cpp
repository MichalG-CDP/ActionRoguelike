// Fill out your copyright notice in the Description page of Project Settings.


#include "Scharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AScharacter::AScharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void AScharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AScharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AScharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called every frame
void AScharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AScharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AScharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

