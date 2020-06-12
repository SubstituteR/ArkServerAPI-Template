#pragma once
#include "init.h"
#include <API/ARK/Ark.h>
#include <Logger/Logger.h>
#include <Tools.h>

DECLARE_HOOK(UseS3, bool, UPrimalLocalProfile*);
bool EnableS3(UPrimalLocalProfile* _this) { return 1; }

BOOL Load()
{
	Log::Get().Init("Test Plugin");
	ArkApi::GetHooks().SetHook("UPrimalLocalProfile.ShouldUploadToS3", &EnableS3, &UseS3_original);
	Log::GetLog()->log(spdlog::level::info, "Test Plugin Loaded!");
#if DEBUG_PLUGIN
	Log::GetLog()->log(spdlog::level::info, "Plugin is in Debug mode!");
#else
	Log::GetLog()->log(spdlog::level::info, "Plugin is in Release mode!");
#endif
	return TRUE;
}

BOOL Unload()
{
	return TRUE;
}
