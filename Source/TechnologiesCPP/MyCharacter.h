// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

//������� ��������� ����������
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

	// ��������� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Points;

	// ������ ����������
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTechnology> Technologies;


public:	
	
	// �������� ������� ����
	int32 GetPoints() const;

	// ���������� ������ ���������� ����� ��������� � ���������
	void AMyCharacter::SetPoints(int32 points);
	
	// �������� ���������� ������� �����
	void ConsumePoints(int32 points);

	// ��������� ������� �� ����� ��� �������� ������(index - ��������� ����������)
	bool EnoughPoints(int32 index);

	// �������� �� ������������ ������� ���� ����������
	bool IsMaxLevel(int32 index);

	// ��������� ������� ����������
	void LevelUpTechnology(int32 index);

	// ���� ������ ������ �������� ������. � ������ �������� �������� ���������� ���� � ����������� �������
	void LevelUpButtonPressed(int32 index);

	// �������� ������ ����������
	TArray<FTechnology> GetTechnologies() const;

	//�������� ������ �� ���� �����������
	void NullAllTechnologies();
};
