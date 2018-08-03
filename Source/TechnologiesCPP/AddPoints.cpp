// Fill out your copyright notice in the Description page of Project Settings.

#include "AddPoints.h"
#include "MyPlayerController.h"

void UAddPoints::NativeConstruct() 
{
	Super::NativeConstruct();

	// ������ ������� ������ Cancel �� ������� CloseWidget
	Cancel->OnClicked.AddDynamic(this, &UAddPoints::CloseWidget);

	// ������ ������� ������ AddButton �� ������� ChooseAndAddPoints ���������� ����� � �������� �������
	AddButton->OnClicked.AddDynamic(this, &UAddPoints::ChooseAndAddPoints);

	Blur->SetBlurStrength(2.0f);

	// ��������� ��������� �� GameMode
	GameMode = Cast<ATechnologiesCPPGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode != nullptr) {
		
		// ��������� ��������� �� ������ ����� ��� ������
		Ranges = &GameMode->AddPointsRanges;

		if (wRangePointsButton) {

			for (int32 index = 0; index < Ranges->Num(); index++) {

				// ������� ������� ������ �� ��������� �����...
				RangePointsButtonInstance = CreateWidget<URangePointsButton>(GetWorld()->GetFirstPlayerController(), wRangePointsButton);
				if (RangePointsButtonInstance != nullptr) {

					// ... � ���������� � �� ���� �������...
					if ((*Ranges)[index].X != (*Ranges)[index].Y) {
						RangePointsButtonInstance->Text->SetText(FText::Format(NSLOCTEXT("NSAddPointsWidget", "AddPointsWidget", "{0}-{1}"), FText::AsNumber((*Ranges)[index].X), FText::AsNumber((*Ranges)[index].Y)));
					}
					else {
						RangePointsButtonInstance->Text->SetText(FText::Format(NSLOCTEXT("NSAddPointsWidget", "AddPointsWidget", "{0}"), FText::AsNumber((*Ranges)[index].X)));
					}

					RangePointsButtonInstance->SetPadding(FMargin(25, 0));

					RangeButtonsContainer->AddChildToHorizontalBox(RangePointsButtonInstance);

					// ... ��������� ������� ������ � ������ ������
					ArrayButtons.Emplace(RangePointsButtonInstance);
				}
			}
		}
	}
}

// ��������� ������
void UAddPoints::CloseWidget()
{
	RemoveFromParent();
}

// ������ ��� ������ ���������
void UAddPoints::EnableAllButtons()
{
	for (auto& Button : ArrayButtons) {
		Button->SetIsEnabled(true);
	}
}

// ��������� ����
void UAddPoints::ChooseAndAddPoints()
{
	PlayerController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	// ���� �� ����� �������...
	for (int32 i = 0; i < ArrayButtons.Num(); i++) {
		// ... ����������� ������ ...
		if (ArrayButtons[i]->GetIsEnabled() == false) {
			// ... ������� ��������� �������� �� ���������� � �������� � �������� � Pawn ...
			PlayerController->ConsumePoints(FMath::RandRange((*Ranges)[i].X, (*Ranges)[i].Y+1));
			// ... � ��������� ���� � �������
			PlayerController->UpdatePoints();
			break;
		}
	}
	RemoveFromParent();
}