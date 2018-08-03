// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/BackgroundBlur.h"
#include "WinMessage.generated.h"

class AMyPlayerController;

/**
 * 
 */
UCLASS()
class TECHNOLOGIESCPP_API UWinMessage : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* Exit;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* RestartGame;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBackgroundBlur* Blur;

	// Перезапуск игры
	UFUNCTION()
	void RestartGameButtonPressed();

	// Выходим из игры
	UFUNCTION()
	void ExitButtonPressed();
	
};
