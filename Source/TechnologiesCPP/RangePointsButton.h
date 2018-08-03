// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"

#include "RangePointsButton.generated.h"

class AMyPlayerController;
/**
 * 
 */
UCLASS()
class TECHNOLOGIESCPP_API URangePointsButton : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* RangeButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text;

	// Выбираем эту кнопку. Делаем неактивной.
	UFUNCTION()
	void SelectThisButton();

	// Указатель на PlayerController
	UPROPERTY()
	AMyPlayerController* PlayerController;
		
};
