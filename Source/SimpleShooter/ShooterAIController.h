// // Copyright Samuel Carriere 2020

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	APawn* TargetPlayerPawn;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};
