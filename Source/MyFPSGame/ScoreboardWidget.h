// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreboardWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYFPSGAME_API UScoreboardWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int DisplayedScore;
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextScore;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextAdditionalScore;

	UFUNCTION(BlueprintCallable, Category = "HitTarget Event")
	void UpdateDisplayedScore(int NewScore);
	
	UFUNCTION(BlueprintCallable, Category = "HitTarget Event")
	void AdditionalScoreDisplay(int Score);
	
	UFUNCTION(BlueprintCallable, Category = "HitTarget Event")
	void AdditionalScoreDisappear();
};
