// Fill out your copyright notice in the Description page of Project Settings.


#include "P38_Pawn.h"
#include "RocketBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AP38_Pawn::AP38_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<ARocketBase> BP_RocketTemplate(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_Rocket.BP_Rocket_C'"));
	if (BP_RocketTemplate.Succeeded())
	{
		RocketTemplate = BP_RocketTemplate.Class;
	}

}

// Called when the game starts or when spawned
void AP38_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP38_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP38_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AP38_Pawn::Fire()
{
	if (RocketTemplate)
	{
		GetWorld()->SpawnActor<AActor>(RocketTemplate, GetActorTransform());
	}
}

/*
* 이건 비행기 회전
*/
void AP38_Pawn::Rotate(float InPitch, float InRoll)
{
	UE_LOG(LogTemp, Warning, TEXT("%f %f"), InPitch, InRoll);
	AddActorLocalRotation(FRotator(InPitch, 0, InRoll) * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * 60.0f);
}

