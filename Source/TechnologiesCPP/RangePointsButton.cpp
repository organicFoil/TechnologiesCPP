// Fill out your copyright notice in the Description page of Project Settings.

#include "RangePointsButton.h"
#include "MyPlayerController.h"

void URangePointsButton::NativeConstruct()
{
	Super::NativeConstruct();

	// ������ ������� ������ RangeButton �� ������� SelectRange
	RangeButton->OnClicked.AddDynamic(this, &URangePointsButton::SelectThisButton);
}

// �������� ��� ������
void URangePointsButton::SelectThisButton()
{
	PlayerController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController != nullptr) {
		// ������� ���������� ��� ������...
		PlayerController->MainWidgetInstance->AddPointsInstance->EnableAllButtons();
		// ... ����� ������ ��� ����������
		SetIsEnabled(false);
	}
}
