// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TechnologiesCPPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TECHNOLOGIESCPP_API ATechnologiesCPPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	// ���������� ����� ��������� ����������
	UPROPERTY(EditAnyWhere, Category = "Game Rules")
	int32 InitialPoints;

	// ������ ��������, ������� ����������� ����� ������
	UPROPERTY(EditAnyWhere, Category = "Game Rules")
	TArray<FVector2D> AddPointsRanges;
	
	
};
