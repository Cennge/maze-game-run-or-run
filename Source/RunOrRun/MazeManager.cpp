#include "MazeManager.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

AMazeManager::AMazeManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMazeManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundBlockers;

	// 1. Ищем все завалы всех типов, которые ты указал в настройках
	for (TSubclassOf<AActor> CurrentClass : BlockerClasses)
	{
		if (CurrentClass)
		{
			TArray<AActor*> TempArray;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), CurrentClass, TempArray);
			FoundBlockers.Append(TempArray); // Скидываем найденное в общий список
		}
	}

	int32 TotalBlockers = FoundBlockers.Num();

	// Если на карте вообще нет завалов, или список классов пуст - ничего не делаем
	if (TotalBlockers == 0) return;

	// 2. Перемешиваем общий список
	for (int32 i = TotalBlockers - 1; i > 0; i--)
	{
		int32 j = FMath::RandRange(0, i);
		FoundBlockers.Swap(i, j);
	}

	// 3. Считаем, сколько завалов нужно удалить
	int32 BlockersToRemove = FMath::RoundToInt(TotalBlockers * PercentOfPathsToOpen);

	// 4. Удаляем (открываем) пути
	for (int32 i = 0; i < BlockersToRemove; i++)
	{
		if (FoundBlockers[i])
		{
			FoundBlockers[i]->Destroy();
		}
	}
}