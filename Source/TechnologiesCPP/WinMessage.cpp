// Fill out your copyright notice in the Description page of Project Settings.

#include "WinMessage.h"
#include "MyPlayerController.h"

void UWinMessage::NativeConstruct()
{
	Super::NativeConstruct();

	// ����������� ����� ������� � ������� ������
	RestartGame->OnClicked.AddDynamic(this, &UWinMessage::RestartGameButtonPressed);
	Exit->OnClicked.AddDynamic(this, &UWinMessage::ExitButtonPressed);

	Blur->SetBlurStrength(2.0f);
}

/* ���������� ����. 
   ��������� ������ Complete.
   ���������� ��� ������ � ����������.
   ������� ������ � ��� ������ � ������
*/
void UWinMessage::RestartGameButtonPressed()
{
	AMyPlayerController* Controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	Controller->MainWidgetInstance->Complete->SetIsEnabled(false);
	Controller->ResetAll();
	Blur->SetBlurStrength(0);
	RemoveFromParent();
}

// ������� �� ����
void UWinMessage::ExitButtonPressed()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}


