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

DECLARE_HOOK(UseS3, bool, UPrimalLocalProfile*);
bool Hook_UseS3(UPrimalLocalProfile* _this) { return 1; }

BOOL Load()
{
	Log::Get().Init("Test Plugin");
	ArkApi::GetHooks().SetHook("UPrimalLocalProfile.ShouldUploadToS3", &Hook_UseS3, &UseS3_original);
	SET_HOOK("UPrimalLocalProfile.ShouldUploadToS3", UseS3);
	Log::GetLog()->log(spdlog::level::info, "Test Plugin Loaded!");
#if DEBUG_PLUGIN
	Log::GetLog()->log(spdlog::level::info, "Debugging is enabled...");

	LOG->info("");

#endif
	return TRUE;
}

BOOL Unload()
{
	DISABLE_HOOK("UPrimalLocalProfile.ShouldUploadToS3", UseS3);
	return TRUE;
}
