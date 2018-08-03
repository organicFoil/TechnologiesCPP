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

	// ���������� � Defaults ������, ������� ����� ��������� � ���� ������
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UTechnologyRow> wRowWidget;

	// ���������� � Defaults ������, ������� ����� ��������� � ���� ������
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UAddPoints> wAddPoints;

	// ���������� � Defaults ������, ������� ����� ��������� � ���� ������
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

	// ��������� �� PlayerController
	UPROPERTY()
	AMyPlayerController* Controller;

	// ��������� �� �������� ������ ����������
	UPROPERTY()
	UTechnologyRow* TechRowInstance;

	// ��������� �� ��������� ������ ������ �����
	UPROPERTY()
	UAddPoints* AddPointsInstance;

	// ��������� �� ��������� ������ ��������� � ������
	UPROPERTY()
	UWinMessage* WinMessageInstance;

	// ��������� ����
	void UpdatePoints(int32 points);

	// ��������� ������� ����������
	void UpdateTechnologiesTable(const TArray<FTechnology>& Technologies);

	// ���������� ������ AddPoints
	UFUNCTION()
	void CallAddPointsWidget();

	// ���� ������ ������ Reset ��� ������ ����� � ������ ����������
	UFUNCTION()
	void ResetButtonPressed();

	// ���� ������ ������ Complete
	UFUNCTION()
	void CompleteButtonPressed();

};
