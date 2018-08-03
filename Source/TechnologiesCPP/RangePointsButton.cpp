// Fill out your copyright notice in the Description page of Project Settings.

#include "RangePointsButton.h"
#include "MyPlayerController.h"

void URangePointsButton::NativeConstruct()
{
	Super::NativeConstruct();

	// Биндим нажатие кнопки RangeButton на функцию SelectRange
	RangeButton->OnClicked.AddDynamic(this, &URangePointsButton::SelectThisButton);
}

// Выбираем эту кнопку
void URangePointsButton::SelectThisButton()
{
	PlayerController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController != nullptr) {
		// Сначала сбрасываем все кнопки...
		PlayerController->MainWidgetInstance->AddPointsInstance->EnableAllButtons();
		// ... затем делаем эту неактивной
		SetIsEnabled(false);
	}
}
