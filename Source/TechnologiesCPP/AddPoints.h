// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/BackgroundBlur.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "TechnologiesCPPGameModeBase.h"
#include "RangePointsButton.h"
#include "AddPoints.generated.h"

class AMyPlayerController;
/**
 * 
 */
UCLASS()
class TECHNOLOGIESCPP_API UAddPoints : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	// Выставляем в Defaults виджет, который будем создавать в этом классе
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<URangePointsButton> wRangePointsButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* AddButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Cancel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* RangeButtonsContainer;

	UPROPERTY(meta = (BindWidget))
	UBackgroundBlur* Blur;
	
	// Закрываем виджет
	UFUNCTION()
	void CloseWidget();

	// Делаем все кнопки активными
	void EnableAllButtons();

	// Добавляем очки
	UFUNCTION()
	void ChooseAndAddPoints();

	// Указатель на массив очков для выбора
	TArray<FVector2D>* Ranges;

	// Массив всех созданных кнопок
	UPROPERTY()
	TArray<URangePointsButton*> ArrayButtons;

	// Указатель на GameMode
	UPROPERTY()
	ATechnologiesCPPGameModeBase* GameMode;

	// Указатель на PlayerController
	UPROPERTY()
	AMyPlayerController* PlayerController;

	// Указатель на кнопку со значением
	UPROPERTY()
	URangePointsButton* RangePointsButtonInstance;

};
