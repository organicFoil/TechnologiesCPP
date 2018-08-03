// Fill out your copyright notice in the Description page of Project Settings.

#include "MainWidget.h"
#include "MyPlayerController.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// ����������� ����� ������� � ������� ������
	AddPoints->OnClicked.AddDynamic(this, &UMainWidget::CallAddPointsWidget);
	Reset->OnClicked.AddDynamic(this, &UMainWidget::ResetButtonPressed);
	Complete->OnClicked.AddDynamic(this, &UMainWidget::CompleteButtonPressed);

	Controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
}

// ��������� ����
void UMainWidget::UpdatePoints(int32 points) {
	CurrentPoints->SetText(FText::Format( NSLOCTEXT("NSMainWidget", "MainWidget", "Points: {0}"), FText::AsNumber(points)));
}

// ��������� ������� ����������
void UMainWidget::UpdateTechnologiesTable(const TArray<FTechnology>& Technologies)
{
	TechnologiesTable->ClearChildren();

	if (wRowWidget) {
		
		for (int32 index = 0; index < Technologies.Num(); index++) {

			// ������� �������� ������ ��� ������ ����������
			TechRowInstance = CreateWidget<UTechnologyRow>(GetWorld()->GetFirstPlayerController(), wRowWidget);

			if (TechRowInstance != nullptr) {
				
				// ���������� ��������� ������� ���������
				float LevelPercent = (1.0f / (float)Technologies[index].MaxLevel) * (float)Technologies[index].Level;
				TechRowInstance->SetName( Technologies[index].Name );
				TechRowInstance->SetLevels(LevelPercent);
				TechRowInstance->SetPercentAsText(LevelPercent);
				TechRowInstance->SetPadding(FMargin(0, 10));
				TechRowInstance->TechnologyIndex = index;
				TechnologiesTable->AddChildToVerticalBox( TechRowInstance );
			}
		}
	}
}

// ���������� ������ AddPoints
void UMainWidget::CallAddPointsWidget()
{
	if (wAddPoints) {
		AddPointsInstance = CreateWidget<UAddPoints>(GetWorld()->GetFirstPlayerController(), wAddPoints);

		if (AddPointsInstance != nullptr) {
			AddPointsInstance->AddToViewport();
		}
	}	
}

// ���� ������ ������ Reset ��� ������ ����� � ������ ����������
void UMainWidget::ResetButtonPressed()
{
	if (Controller != nullptr) {
		Controller->ResetAll();
	}
}

// ���� ������ ������ Complete
void UMainWidget::CompleteButtonPressed()
{
	if (wWinMessage) {
		WinMessageInstance = CreateWidget<UWinMessage>(GetWorld()->GetFirstPlayerController(), wWinMessage);

		if (WinMessageInstance != nullptr) {
			WinMessageInstance->AddToViewport();
		}
	}
}