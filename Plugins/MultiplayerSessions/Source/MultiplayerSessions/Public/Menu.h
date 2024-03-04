// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BLueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections, FString TypeOfMatch = FString(TEXT("FreeForAll")),FString LobbyPath = FString(TEXT("/Game/ThirdPErson/Maps/Lobby")));

	//
	// Callbacks for the custom delegatyes on the MultiplayerSessionsSubsystem
	//
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessiont(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);


protected:
	virtual bool Initialize() override; 
	virtual void NativeDestruct() override;


private:
	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();

	// The subsystem designed to handle all online session functionality
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections;
	FString MatchType{ TEXT("FreeForAll") };
	FString PathToLobby{TEXT("/Game/ThirdPErson/Maps/Lobby")};
	
};
