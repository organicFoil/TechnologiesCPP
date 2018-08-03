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

	// ��������� �� ������� ������ � ��
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UMainWidget> wMainWidget;
	


public:
	
	// ��������� �� Pawn
	UPROPERTY()
	AMyCharacter* MyCharacter;

	// ��������� �� GameMode
	UPROPERTY()
	ATechnologiesCPPGameModeBase* GameMode;

	// ��������� �� ��������� ������� ������
	UPROPERTY()
	UMainWidget* MainWidgetInstance;
	
	// ��������� ������� � ���� ��������� ����������
	void LevelUpThreeRandomTechnologies();

	// ��������� ������� ������� ���������� � MainWidget
	void UpdateTechnologiesTable();

	// ��������� ���� � MainWidget
	void UpdatePoints();

	// ��������� ���� � MyCharacter
	void ConsumePoints(int32 points);

	// ��������� ������� � ���������� �� ������� (����� ��������� � Pawn)
	void LevelUpButtonPressed(int32 Index);

	// �������� ������ ���������� � ���� � ������������ ���������
	UFUNCTION()
	void ResetAll();

};
