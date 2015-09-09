// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class SUMOBOT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
			float Health = 100;		//default 100
		/*
			Blue print can read from it and write to it
			EditAnywhere - other classes can access it and change it if they need to
			We are going to put it in a category
		*/
	
	// Make an isDead property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;		// default false

	// Calculate death function (helper)
	virtual void CalculateDead();

	// Calculate our actual health function
	UFUNCTION(BlueprintCallable, Category = "Base Character")
	virtual void CalculateHealth(float delta);		// delta - the change in health
		/* BlueprintCallable essentially turns this function into a node in blueprint */

#if WITH_EDITOR
	// Editor-centric code for changing properties
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) overide;
	//notify from the editor saying you changed som event
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
