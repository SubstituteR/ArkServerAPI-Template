#pragma once
/*
 *								READ ME
 *	This file controls what is loaded and unloaded in the plugin.
 *	You should put your hooks/commands in here.
*/
#include "init.h"
#include <API/ARK/Ark.h>
#include <Logger/Logger.h>
#include <Tools.h>
#include <singleton.h>
#include <macros.h>
#include <fstream>
#include "json.hpp"
#include <unordered_set>


DECLARE_HOOK(validateName, void, AShooterPlayerState*, FPrimalPlayerCharacterConfigStructReplicated*);

nlohmann::json config;
std::unordered_set<std::string> disallowedNames;

void Hook_validateName(AShooterPlayerState* _this, FPrimalPlayerCharacterConfigStructReplicated* playerCharacterConfig)
{
    if (disallowedNames.find(playerCharacterConfig->PlayerCharacterName.ToString()) != disallowedNames.end())
        return ArkApi::GetApiUtils().SendNotification(_this->GetShooterController(), FLinearColor(1.f, 0.f, 0.f, 1.f), 4.f, 8.5f, nullptr, "This name is disallowed.");
    validateName_original(_this, playerCharacterConfig);
}

//Adapted from https://github.com/Michidu/Ark-Server-Plugins/blob/master/ArkAdvert/ArkAdvert/ArkAdvert.cpp
void ReadConfig()
{
	const std::string config_path = ArkApi::Tools::GetCurrentDir() + "/ArkApi/Plugins/DisallowedNames/config.json";
	std::ifstream file{ config_path };
	if (!file.is_open())
		throw std::runtime_error("Can't open config.json");

	file >> config;
	file.close();
}

void ReloadConfig(APlayerController* player_controller, FString*, bool)
{
	AShooterPlayerController* shooter_controller = static_cast<AShooterPlayerController*>(player_controller);
	try { ReadConfig(); }
	catch (const std::exception& error)
	{
		API_UTILS.SendServerMessage(shooter_controller, FColorList::Red, "Failed to reload config");
		Log::GetLog()->error(error.what());
		return;
	}
	API_UTILS.SendServerMessage(shooter_controller, FColorList::Green, "Reloaded config");
}



BOOL Load()
{
	Log::Get().Init("Disallowed Names");
	ReadConfig();
    disallowedNames = config["DisallowedNames"]["BlockedList"].get<std::unordered_set<std::string>>();
    SET_HOOK("AShooterPlayerState.ServerRequestCreateNewPlayer_Implementation", validateName);
	COMMANDS.AddConsoleCommand("DisallowedNames.Reload", ReloadConfig);
	return TRUE;
}

BOOL Unload()
{
    DISABLE_HOOK("AShooterPlayerState.ServerRequestCreateNewPlayer_Implementation", validateName);
	COMMANDS.RemoveConsoleCommand("DisallowedNames.Reload");
	return TRUE;
}
