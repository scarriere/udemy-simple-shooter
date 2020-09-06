// // Copyright Samuel Carriere 2020


#include "BTService_PlayerLocationIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Set Player Location If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	APawn* TargetPlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (TargetPlayerPawn == nullptr) return;

	AAIController* AIController = Cast<AAIController>(OwnerComp.GetAIOwner());

	if (AIController == nullptr) return;

	if (AIController->LineOfSightTo(TargetPlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), TargetPlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
