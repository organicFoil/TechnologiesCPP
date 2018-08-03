// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"


void AMyPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	MyCharacter = Cast<AMyCharacter>(InPawn);
	
	if (MyCharacter != nullptr) {

		// ���������� ����������� ���������� �����
		GameMode = Cast<ATechnologiesCPPGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode != nullptr) {
			MyCharacter->SetPoints(GameMode->InitialPoints);
		}

		// ��������� ��������� �� ������ � BP
		if (wMainWidget) {

			// ������� � ��������� ������
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

// ��������� ������� � ���� ��������� ����������
void AMyPlayerController::LevelUpThreeRandomTechnologies()
{
	const TArray<FTechnology>& technologies = MyCharacter->GetTechnologies();
	int32 technologiesLastIndex = technologies.Num() - 1;
	TArray<int32> randomIndexes;

	// �������� ������ ��������� �������� ���� �� ��������� 3 ����������
	while (randomIndexes.Num() < 3) {
		int32 randomIndex = FMath::RandRange(0, technologiesLastIndex);
		randomIndexes.AddUnique(randomIndex);
	}

	// ��������� ������� ������� ������� � ������� ��������� ��������
	for (auto& index : randomIndexes) {
		MyCharacter->LevelUpTechnology(index);
	}
}

// ��������� ������� ������� ���������� � MainWidget
void AMyPlayerController::UpdateTechnologiesTable()
{
	if (MainWidgetInstance != nullptr) {
		MainWidgetInstance->UpdateTechnologiesTable(MyCharacter->GetTechnologies());
	}
}

// ��������� ���� � MainWidget
void AMyPlayerController::UpdatePoints()
{
	if (MainWidgetInstance != nullptr) {
		MainWidgetInstance->UpdatePoints(MyCharacter->GetPoints());
	}
}

// ��������� ���� � MyCharacter
void AMyPlayerController::ConsumePoints(int32 points)
{
	if (MyCharacter != nullptr) {
		MyCharacter->ConsumePoints(points);
	}
}

// �������� ������ ���������� � ��������� ����� (����� ��������� � Pawn)
void AMyPlayerController::LevelUpButtonPressed(int32 Index)
{
	if (MyCharacter != nullptr) {
		// ���� ���������� ������������� ������ �� �� ���� ������ ������
		if ( !(MyCharacter->IsMaxLevel(Index)) ) {
			MyCharacter->LevelUpButtonPressed(Index);
			UpdatePoints();

			// �������� ������� ������. ���� ��� ���������� �������� ���� ������ � ��� ���� �� �������� �����, �� ���������� ������ Complete
			if (MyCharacter->IsMaxLevel(Index) && MyCharacter->GetPoints() == 0) {
				if (MainWidgetInstance != nullptr) {
					MainWidgetInstance->Complete->SetIsEnabled(true);
				}
			}
		}
	}
}

// �������� ������ ���������� � ���� � ������������ ���������
void AMyPlayerController::ResetAll()
{
	if (MyCharacter != nullptr) {

		// �������� ������ ����������
		MyCharacter->NullAllTechnologies();

		// ���������� ����������� ���������� �����
		if (GameMode != nullptr) {
			MyCharacter->SetPoints(GameMode->InitialPoints);
		}

		// ��������� ������� ���� ��������� ����������� � ��������� ���� ������
		LevelUpThreeRandomTechnologies();
		UpdateTechnologiesTable();
		UpdatePoints();
	}
}