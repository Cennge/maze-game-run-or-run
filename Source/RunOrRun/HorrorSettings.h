#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "HorrorSettings.generated.h"

UCLASS()
class RUNORRUN_API UHorrorSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UHorrorSettings();

	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	static UHorrorSettings* GetHorrorSettings();

	// --- ЧУВСТВИТЕЛЬНОСТЬ МЫШИ ---
	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	void SetMouseSensitivity(float NewSensitivity);

	UFUNCTION(BlueprintPure, Category = "Horror Settings")
	float GetMouseSensitivity() const;

	// --- ОБЩАЯ ГРОМКОСТЬ ---
	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	void SetMasterVolume(float NewVolume);

	UFUNCTION(BlueprintPure, Category = "Horror Settings")
	float GetMasterVolume() const;

	// --- ГРОМКОСТЬ МУЗЫКИ ---
	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	void SetMusicVolume(float NewVolume);

	UFUNCTION(BlueprintPure, Category = "Horror Settings")
	float GetMusicVolume() const;

	// --- ГРОМКОСТЬ ЭФФЕКТОВ (SFX) ---
	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	void SetSFXVolume(float NewVolume);

	UFUNCTION(BlueprintPure, Category = "Horror Settings")
	float GetSFXVolume() const;

	// --- ЯРКОСТЬ (ГАММА) ---
	UFUNCTION(BlueprintCallable, Category = "Horror Settings")
	void SetBrightness(float NewBrightness);

	UFUNCTION(BlueprintPure, Category = "Horror Settings")
	float GetBrightness() const;

protected:
	UPROPERTY(Config)
	float MouseSensitivity;

	UPROPERTY(Config)
	float MasterVolume;

	UPROPERTY(Config)
	float MusicVolume;

	UPROPERTY(Config)
	float SFXVolume;

	UPROPERTY(Config)
	float Brightness;
};