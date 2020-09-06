// // Copyright Samuel Carriere 2020


#include "BTTask_Shoot.h"
#include "ShooterCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) return EBTNodeResult::Failed;

	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if (ShooterCharacter == nullptr) return EBTNodeResult::Failed;
	
	ShooterCharacter->PullTrigger();

	return EBTNodeResult::Succeeded;
}