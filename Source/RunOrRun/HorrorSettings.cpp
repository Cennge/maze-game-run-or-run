#include "HorrorSettings.h"

UHorrorSettings::UHorrorSettings()
{
	// Значения по умолчанию при первом запуске
	MouseSensitivity = 1.0f;
	MasterVolume = 1.0f;
	MusicVolume = 1.0f;
	SFXVolume = 1.0f;
	Brightness = 2.2f; // Стандартная гамма в UE
}

UHorrorSettings* UHorrorSettings::GetHorrorSettings()
{
	return Cast<UHorrorSettings>(UGameUserSettings::GetGameUserSettings());
}

void UHorrorSettings::SetMouseSensitivity(float NewSensitivity)
{
	MouseSensitivity = NewSensitivity;
	SaveConfig();
}

float UHorrorSettings::GetMouseSensitivity() const { return MouseSensitivity; }

void UHorrorSettings::SetMasterVolume(float NewVolume)
{
	MasterVolume = NewVolume;
	SaveConfig();
}

float UHorrorSettings::GetMasterVolume() const { return MasterVolume; }

void UHorrorSettings::SetMusicVolume(float NewVolume)
{
	MusicVolume = NewVolume;
	SaveConfig();
}

float UHorrorSettings::GetMusicVolume() const { return MusicVolume; }

void UHorrorSettings::SetSFXVolume(float NewVolume)
{
	SFXVolume = NewVolume;
	SaveConfig();
}

float UHorrorSettings::GetSFXVolume() const { return SFXVolume; }

void UHorrorSettings::SetBrightness(float NewBrightness)
{
	Brightness = NewBrightness;
	SaveConfig();
}

float UHorrorSettings::GetBrightness() const { return Brightness; }