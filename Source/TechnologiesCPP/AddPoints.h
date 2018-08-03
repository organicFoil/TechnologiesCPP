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

	// ���������� � Defaults ������, ������� ����� ��������� � ���� ������
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
	
	// ��������� ������
	UFUNCTION()
	void CloseWidget();

	// ������ ��� ������ ���������
	void EnableAllButtons();

	// ��������� ����
	UFUNCTION()
	void ChooseAndAddPoints();

	// ��������� �� ������ ����� ��� ������
	TArray<FVector2D>* Ranges;

	// ������ ���� ��������� ������
	UPROPERTY()
	TArray<URangePointsButton*> ArrayButtons;

	// ��������� �� GameMode
	UPROPERTY()
	ATechnologiesCPPGameModeBase* GameMode;

	// ��������� �� PlayerController
	UPROPERTY()
	AMyPlayerController* PlayerController;

	// ��������� �� ������ �� ���������
	UPROPERTY()
	URangePointsButton* RangePointsButtonInstance;

};
