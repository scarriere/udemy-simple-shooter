// // Copyright Samuel Carriere 2020


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	TargetPlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetPlayerPawn == nullptr) return;

	if (LineOfSightTo(TargetPlayerPawn))
	{
		SetFocus(TargetPlayerPawn);
		MoveToActor(TargetPlayerPawn, AcceptanceRadius);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
}