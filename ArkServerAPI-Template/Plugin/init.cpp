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

DECLARE_HOOK(UseS3, bool, UPrimalLocalProfile*);
bool EnableS3(UPrimalLocalProfile* _this) { return 1; }

BOOL Load()
{
	Log::Get().Init("Test Plugin");
	ArkApi::GetHooks().SetHook("UPrimalLocalProfile.ShouldUploadToS3", &EnableS3, &UseS3_original);
	Log::GetLog()->log(spdlog::level::info, "Test Plugin Loaded!");
#if DEBUG_PLUGIN
	Log::GetLog()->log(spdlog::level::info, "Debugging is enabled...");
#endif
	return TRUE;
}

BOOL Unload()
{
	ArkApi::GetHooks().DisableHook("UPrimalLocalProfile.ShouldUploadToS3", &EnableS3);
	return TRUE;
}
