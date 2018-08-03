// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "TechnologyRow.h"
#include "AddPoints.h"
#include "WinMessage.h"
#include "MyCharacter.h"
#include "MainWidget.generated.h"

class AMyPlayerController;

UCLASS()
class TECHNOLOGIESCPP_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	// Выставляем в Defaults виджет, который будем создавать в этом классе
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UTechnologyRow> wRowWidget;

	// Выставляем в Defaults виджет, который будем создавать в этом классе
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UAddPoints> wAddPoints;

	// Выставляем в Defaults виджет, который будем создавать в этом классе
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UWinMessage> wWinMessage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* CurrentPoints;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* TechnologiesTable;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* AddPoints;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Reset;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Complete;

	// Указатель на PlayerController
	UPROPERTY()
	AMyPlayerController* Controller;

	// Указатель на строчный виджет технологии
	UPROPERTY()
	UTechnologyRow* TechRowInstance;

	// Указатель на созданный виджет выбора очков
	UPROPERTY()
	UAddPoints* AddPointsInstance;

	// Указатель на созданный виджет сообщения о победе
	UPROPERTY()
	UWinMessage* WinMessageInstance;

	// Обновляем очки
	void UpdatePoints(int32 points);

	// Обновляем таблицу технологий
	void UpdateTechnologiesTable(const TArray<FTechnology>& Technologies);

	// Отображаем виджет AddPoints
	UFUNCTION()
	void CallAddPointsWidget();

	// Была нажата кнопка Reset для сброса очков и уровня технологий
	UFUNCTION()
	void ResetButtonPressed();

	// Была нажата кнопка Complete
	UFUNCTION()
	void CompleteButtonPressed();

};
