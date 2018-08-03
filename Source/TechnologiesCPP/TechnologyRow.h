// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "TechnologyRow.generated.h"

/**
 * 
 */
UCLASS()
class TECHNOLOGIESCPP_API UTechnologyRow : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* Name;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* Levels;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* LevelsAsPercent;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PercentAsText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* AddLevel;

	// Этот индекс соответствует индексу элемента в массиве технологий (который изначально задан)
	UPROPERTY()
	int32 TechnologyIndex;

	// Выставляем имя в текстовом блоке
	void SetName(FString name);

	// Выставляем процент в прогрессБаре
	void SetLevels(float level);
	
	// Выставляем процент в текстовом блоке
	void SetPercentAsText(float percent);

	// Была нажата кнопка поднятия уровня у технологии
	UFUNCTION()
	void AddLevelButtonPressed();
};
