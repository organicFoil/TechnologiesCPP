// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// ѕолучаем текущие очки
int32 AMyCharacter::GetPoints() const
{
	return Points;
}

// ¬ыставл€ем точное количество очков указанное в параметре
void AMyCharacter::SetPoints(int32 points)
{
	Points = points;
}

// »змен€ем количество текущих очков относительно вход€щего параметра
void AMyCharacter::ConsumePoints(int32 points)
{
	Points += points;
}

// ѕровер€ем хватает ли очков дл€ подн€ти€ уровн€(index - выбранна€ технологи€)
bool AMyCharacter::EnoughPoints(int32 index)
{
	int32 requiredPoints;
	if (Technologies[index].bDoublePoints) {
		requiredPoints = pow(2, Technologies[index].Level);
		return Points >= requiredPoints;
	}
	else {
		requiredPoints = (Technologies[index].Level + 1);
		return Points >= requiredPoints;
	}
	
}

// ѕроверка на максимальный уровень этой технологии
bool AMyCharacter::IsMaxLevel(int32 index)
{
	return Technologies[index].Level >= Technologies[index].MaxLevel;
}

// ѕоднимаем уровень технологии
void AMyCharacter::LevelUpTechnology(int32 index)
{
	Technologies[index].Level += 1;
}

// Ѕыла нажата кнопка подн€ти€ уровн€ (в случае успешной проверки вычитаютс€ очки и поднимаетс€ уровень)
void AMyCharacter::LevelUpButtonPressed(int32 index)
{
	// ≈сли хватает очков...
	if (EnoughPoints(index)) {
		// ... то выбираем сколько надо отн€ть очков
		if (Technologies[index].bDoublePoints) {
			ConsumePoints( -(pow(2, Technologies[index].Level)) );
		}
		else {
			ConsumePoints( -(Technologies[index].Level + 1) );
		}
		// ... и затем поднимаем уровень
		LevelUpTechnology(index);
	}
}

// ѕолучаем массив технологий
TArray<FTechnology> AMyCharacter::GetTechnologies() const
{
	return Technologies;
}

//ќбнул€ем уровни во всех технологи€х
void AMyCharacter::NullAllTechnologies()
{
	for (auto& Technology : Technologies) {
		Technology.Level = 0;
	}
}