// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreboardWidget.h"

#include "Components/TextBlock.h"

void UScoreboardWidget::NativeConstruct()
{
	// Call the Blueprint "Event Construct" node
    Super::NativeConstruct();
    
    // ItemTitle can be nullptr if we haven't created it in the
    // Blueprint subclass
	DisplayedScore = 0;
    if (TextScore)
    {
    	//ItemTitle->SetText(TEXT("Hello world!"));
    	FString StrScore = "Score: ";
    	//TextScore->SetText(FText::FromString(StrScore + std::to_string(Score)) + hh);
    	TextScore->SetText(FText::FromString(StrScore + FString::FromInt(DisplayedScore)));
    }
}

void UScoreboardWidget::UpdateDisplayedScore(int NewScore)
{
	//if(GEngine)
    //     GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Update Displayed Score!"));   
	//APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	////DisplayedScore += Delta;
	//DisplayedScore = PlayerCharacter->GetScore();
	DisplayedScore = NewScore;
    if (TextScore)
    {
    	//ItemTitle->SetText(TEXT("Hello world!"));
    	FString StrScore = "Score: ";
    	//TextScore->SetText(FText::FromString(StrScore + std::to_string(Score)) + hh);
    	TextScore->SetText(FText::FromString(StrScore + FString::FromInt(DisplayedScore)));
    }
}

void UScoreboardWidget::AdditionalScoreDisplay(int Score)
{
    if (TextAdditionalScore)
    {
    	//ItemTitle->SetText(TEXT("Hello world!"));
    	FString StrScore = "+ ";
    	//TextScore->SetText(FText::FromString(StrScore + std::to_string(Score)) + hh);
    	TextAdditionalScore->SetText(FText::FromString(StrScore + FString::FromInt(Score)));
    }
}
	
void UScoreboardWidget::AdditionalScoreDisappear()
{
	
    if (TextAdditionalScore)
    {
    	//ItemTitle->SetText(TEXT("Hello world!"));
    	FString StrScore = " ";
    	//TextScore->SetText(FText::FromString(StrScore + std::to_string(Score)) + hh);
    	TextAdditionalScore->SetText(FText::FromString(StrScore));
    }
}
