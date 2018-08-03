// Fill out your copyright notice in the Description page of Project Settings.

#include "TechnologyRow.h"
#include "MyPlayerController.h"

void UTechnologyRow::NativeConstruct()
{
	Super::NativeConstruct();
	
	// Биндим нажатие кнопки AddLevel к функции AddLevelButtonPressed
	AddLevel->OnClicked.AddDynamic(this, &UTechnologyRow::AddLevelButtonPressed);
}

// Выставляем имя в текстовом блоке
void UTechnologyRow::SetName(FString name)
{
	Name->SetText(FText::FromString(name));
}

// Выставляем процент в прогрессБаре
void UTechnologyRow::SetLevels(float level)
{
	Levels->SetPercent(level);
	LevelsAsPercent->SetPercent(level);
	if (level >= 1.0f) {
		LevelsAsPercent->SetFillColorAndOpacity(FColor::FromHex("2CFF30FF"));
	}
}

// Выставляем процент в текстовом блоке
void UTechnologyRow::SetPercentAsText(float percent)
{
	PercentAsText->SetText(FText::Format(NSLOCTEXT("NSTechnologyRow", "TechnologyRow", "{0}% completed"), FText::AsNumber(percent*100)));
}

// Была нажата кнопка поднятия уровня у технологии
void UTechnologyRow::AddLevelButtonPressed()
{
	AMyPlayerController* Controller = Cast<AMyPlayerController>( GetWorld()->GetFirstPlayerController() );
	if (Controller) {
		Controller->LevelUpButtonPressed(TechnologyIndex);
		Controller->UpdateTechnologiesTable();
	}
}
