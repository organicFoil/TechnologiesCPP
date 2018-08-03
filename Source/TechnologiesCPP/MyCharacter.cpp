// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// �������� ������� ����
int32 AMyCharacter::GetPoints() const
{
	return Points;
}

// ���������� ������ ���������� ����� ��������� � ���������
void AMyCharacter::SetPoints(int32 points)
{
	Points = points;
}

// �������� ���������� ������� ����� ������������ ��������� ���������
void AMyCharacter::ConsumePoints(int32 points)
{
	Points += points;
}

// ��������� ������� �� ����� ��� �������� ������(index - ��������� ����������)
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

// �������� �� ������������ ������� ���� ����������
bool AMyCharacter::IsMaxLevel(int32 index)
{
	return Technologies[index].Level >= Technologies[index].MaxLevel;
}

// ��������� ������� ����������
void AMyCharacter::LevelUpTechnology(int32 index)
{
	Technologies[index].Level += 1;
}

// ���� ������ ������ �������� ������ (� ������ �������� �������� ���������� ���� � ����������� �������)
void AMyCharacter::LevelUpButtonPressed(int32 index)
{
	// ���� ������� �����...
	if (EnoughPoints(index)) {
		// ... �� �������� ������� ���� ������ �����
		if (Technologies[index].bDoublePoints) {
			ConsumePoints( -(pow(2, Technologies[index].Level)) );
		}
		else {
			ConsumePoints( -(Technologies[index].Level + 1) );
		}
		// ... � ����� ��������� �������
		LevelUpTechnology(index);
	}
}

// �������� ������ ����������
TArray<FTechnology> AMyCharacter::GetTechnologies() const
{
	return Technologies;
}

//�������� ������ �� ���� �����������
void AMyCharacter::NullAllTechnologies()
{
	for (auto& Technology : Technologies) {
		Technology.Level = 0;
	}
}