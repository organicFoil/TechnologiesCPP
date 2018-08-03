// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

//Создаем структуру технологии
USTRUCT(BlueprintType)
struct FTechnology
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxLevel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bDoublePoints;
};

UCLASS()
class TECHNOLOGIESCPP_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()	
	
public:
	// Sets default values for this character's properties
	AMyCharacter();
	

protected:

	// Доступные очки
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Points;

	// Массив технологий
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTechnology> Technologies;


public:	
	
	// Получаем текущие очки
	int32 GetPoints() const;

	// Выставляем точное количество очков указанное в параметре
	void AMyCharacter::SetPoints(int32 points);
	
	// Изменяем количество текущих очков
	void ConsumePoints(int32 points);

	// Проверяем хватает ли очков для поднятия уровня(index - выбранная технология)
	bool EnoughPoints(int32 index);

	// Проверка на максимальный уровень этой технологии
	bool IsMaxLevel(int32 index);

	// Поднимаем уровень технологии
	void LevelUpTechnology(int32 index);

	// Была нажата кнопка поднятия уровня. В случае успешной проверки вычитаются очки и поднимается уровень
	void LevelUpButtonPressed(int32 index);

	// Получаем массив технологий
	TArray<FTechnology> GetTechnologies() const;

	//Обнуляем уровни во всех технологиях
	void NullAllTechnologies();
};
