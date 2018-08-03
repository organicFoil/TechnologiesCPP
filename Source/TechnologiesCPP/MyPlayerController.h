// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TechnologiesCPPGameModeBase.h"
#include "MyCharacter.h"
#include "MainWidget.h"
#include "MyPlayerController.generated.h"


UCLASS()
class TECHNOLOGIESCPP_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void Possess(APawn* InPawn) override;

private:

	// Ссылаемся на главный виджет в ВР
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UMainWidget> wMainWidget;
	


public:
	
	// Указатель на Pawn
	UPROPERTY()
	AMyCharacter* MyCharacter;

	// Указатель на GameMode
	UPROPERTY()
	ATechnologiesCPPGameModeBase* GameMode;

	// Указатель на созданный главный виджет
	UPROPERTY()
	UMainWidget* MainWidgetInstance;
	
	// Поднимаем уровень у трех случайных технологий
	void LevelUpThreeRandomTechnologies();

	// Обновляем главную таблицу технологий в MainWidget
	void UpdateTechnologiesTable();

	// Обновляем очки в MainWidget
	void UpdatePoints();

	// Добавляем очки в MyCharacter
	void ConsumePoints(int32 points);

	// Поднимаем уровень у технологии по индексу (через обращение к Pawn)
	void LevelUpButtonPressed(int32 Index);

	// Сбросить уровни технологий и очки к изначальному состоянию
	UFUNCTION()
	void ResetAll();

};
