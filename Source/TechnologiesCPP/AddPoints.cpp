// Fill out your copyright notice in the Description page of Project Settings.

#include "AddPoints.h"
#include "MyPlayerController.h"

void UAddPoints::NativeConstruct() 
{
	Super::NativeConstruct();

	// Биндим нажатие кнопки Cancel на функцию CloseWidget
	Cancel->OnClicked.AddDynamic(this, &UAddPoints::CloseWidget);

	// Биндим нажатие кнопки AddButton на функцию ChooseAndAddPoints добавления очков и закрытия виджета
	AddButton->OnClicked.AddDynamic(this, &UAddPoints::ChooseAndAddPoints);

	Blur->SetBlurStrength(2.0f);

	// Сохраняем указатель на GameMode
	GameMode = Cast<ATechnologiesCPPGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode != nullptr) {
		
		// Сохраняем указатель на массив очков для выбора
		Ranges = &GameMode->AddPointsRanges;

		if (wRangePointsButton) {

			for (int32 index = 0; index < Ranges->Num(); index++) {

				// Создаем инстанс кнопки со значением очков...
				RangePointsButtonInstance = CreateWidget<URangePointsButton>(GetWorld()->GetFirstPlayerController(), wRangePointsButton);
				if (RangePointsButtonInstance != nullptr) {

					// ... и записываем в неё очки текстом...
					if ((*Ranges)[index].X != (*Ranges)[index].Y) {
						RangePointsButtonInstance->Text->SetText(FText::Format(NSLOCTEXT("NSAddPointsWidget", "AddPointsWidget", "{0}-{1}"), FText::AsNumber((*Ranges)[index].X), FText::AsNumber((*Ranges)[index].Y)));
					}
					else {
						RangePointsButtonInstance->Text->SetText(FText::Format(NSLOCTEXT("NSAddPointsWidget", "AddPointsWidget", "{0}"), FText::AsNumber((*Ranges)[index].X)));
					}

					RangePointsButtonInstance->SetPadding(FMargin(25, 0));

					RangeButtonsContainer->AddChildToHorizontalBox(RangePointsButtonInstance);

					// ... добавляем инстанс кнопки в массив кнопок
					ArrayButtons.Emplace(RangePointsButtonInstance);
				}
			}
		}
	}
}

// Закрываем виджет
void UAddPoints::CloseWidget()
{
	RemoveFromParent();
}

// Делаем все кнопки активными
void UAddPoints::EnableAllButtons()
{
	for (auto& Button : ArrayButtons) {
		Button->SetIsEnabled(true);
	}
}

// Добавляем очки
void UAddPoints::ChooseAndAddPoints()
{
	PlayerController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	// Ищем по всему массиву...
	for (int32 i = 0; i < ArrayButtons.Num(); i++) {
		// ... выключенную кнопку ...
		if (ArrayButtons[i]->GetIsEnabled() == false) {
			// ... находим рандомное значение из промежутка и доавляем к значению в Pawn ...
			PlayerController->ConsumePoints(FMath::RandRange((*Ranges)[i].X, (*Ranges)[i].Y+1));
			// ... и обновляем очки в виджете
			PlayerController->UpdatePoints();
			break;
		}
	}
	RemoveFromParent();
}