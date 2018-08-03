// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"


void AMyPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	MyCharacter = Cast<AMyCharacter>(InPawn);
	
	if (MyCharacter != nullptr) {

		// ¬ыставл€ем изначальное количество очков
		GameMode = Cast<ATechnologiesCPPGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode != nullptr) {
			MyCharacter->SetPoints(GameMode->InitialPoints);
		}

		// ѕровер€ем выставили ли виджет в BP
		if (wMainWidget) {

			// —оздаем и сохран€ем виджет
			MainWidgetInstance = CreateWidget<UMainWidget>(this, wMainWidget);

			if (MainWidgetInstance != nullptr) {
				MainWidgetInstance->AddToViewport();

				MainWidgetInstance->UpdatePoints(MyCharacter->GetPoints());

				LevelUpThreeRandomTechnologies();
				UpdateTechnologiesTable();
			}
			bShowMouseCursor = true;
		}
	}
	
}

// ѕоднимаем уровень у трех случайных технологий
void AMyPlayerController::LevelUpThreeRandomTechnologies()
{
	const TArray<FTechnology>& technologies = MyCharacter->GetTechnologies();
	int32 technologiesLastIndex = technologies.Num() - 1;
	TArray<int32> randomIndexes;

	// —обираем массив случайных индексов пока не наберетс€ 3 уникальных
	while (randomIndexes.Num() < 3) {
		int32 randomIndex = FMath::RandRange(0, technologiesLastIndex);
		randomIndexes.AddUnique(randomIndex);
	}

	// ѕоднимаем уровень каждому индексу в массиве случайных индексов
	for (auto& index : randomIndexes) {
		MyCharacter->LevelUpTechnology(index);
	}
}

// ќбновл€ем главную таблицу технологий в MainWidget
void AMyPlayerController::UpdateTechnologiesTable()
{
	if (MainWidgetInstance != nullptr) {
		MainWidgetInstance->UpdateTechnologiesTable(MyCharacter->GetTechnologies());
	}
}

// ќбновл€ем очки в MainWidget
void AMyPlayerController::UpdatePoints()
{
	if (MainWidgetInstance != nullptr) {
		MainWidgetInstance->UpdatePoints(MyCharacter->GetPoints());
	}
}

// ƒобавл€ем очки в MyCharacter
void AMyPlayerController::ConsumePoints(int32 points)
{
	if (MyCharacter != nullptr) {
		MyCharacter->ConsumePoints(points);
	}
}

// ѕодн€тие уровн€ технологии с просчетом очков (через обращение к Pawn)
void AMyPlayerController::LevelUpButtonPressed(int32 Index)
{
	if (MyCharacter != nullptr) {
		// ≈сли технологи€ максимального уровн€ то не надо ничего делать
		if ( !(MyCharacter->IsMaxLevel(Index)) ) {
			MyCharacter->LevelUpButtonPressed(Index);
			UpdatePoints();

			// ѕроверка услови€ победы. ≈сли эта технологи€ достигла макс уровн€ и при этом не осталось очков, то активируем кнопку Complete
			if (MyCharacter->IsMaxLevel(Index) && MyCharacter->GetPoints() == 0) {
				if (MainWidgetInstance != nullptr) {
					MainWidgetInstance->Complete->SetIsEnabled(true);
				}
			}
		}
	}
}

// —бросить уровни технологий и очки к изначальному состо€нию
void AMyPlayerController::ResetAll()
{
	if (MyCharacter != nullptr) {

		// ќбнул€ем уровни технологий
		MyCharacter->NullAllTechnologies();

		// ¬ыставл€ем изначальное количество очков
		if (GameMode != nullptr) {
			MyCharacter->SetPoints(GameMode->InitialPoints);
		}

		// ѕоднимаем уровень трем случайным технологи€м и обновл€ем весь виджет
		LevelUpThreeRandomTechnologies();
		UpdateTechnologiesTable();
		UpdatePoints();
	}
}