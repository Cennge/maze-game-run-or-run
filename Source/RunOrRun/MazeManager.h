#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeManager.generated.h"

UCLASS()
class RUNORRUN_API AMazeManager : public AActor
{
	GENERATED_BODY()

public:
	AMazeManager();

protected:
	virtual void BeginPlay() override;

public:
	// Теперь это МАССИВ классов. Сюда можно добавить и двери, и мусор, и всё что угодно!
	UPROPERTY(EditAnywhere, Category = "Maze Settings")
	TArray<TSubclassOf<AActor>> BlockerClasses;

	// Процент проходов, которые мы хотим ОСВОБОДИТЬ (0.0 - все закрыты, 1.0 - все открыты)
	UPROPERTY(EditAnywhere, Category = "Maze Settings", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float PercentOfPathsToOpen = 0.5f;
};