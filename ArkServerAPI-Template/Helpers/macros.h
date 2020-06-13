/**
 * Some macros to help new users.
 * These should also be useful to experienced users
 * as it should help in keeping names consistent.
 *
 */
#include <API/ARK/Ark.h>

/* Macro to add a hook easily. */
#define SET_HOOK(functionName, hookName) \
ArkApi::GetHooks().SetHook(functionName, &Hook_ ## hookName, &hookName ## _original)
/* Macro to remove a hook easily. */
#define DISABLE_HOOK(functionName, hookName) \
ArkApi::GetHooks().DisableHook(functionName, &Hook_ ## hookName)
/* Shortcut */
#define HOOKS \
ArkApi::GetHooks()
/* Shortcut */
#define COMMANDS \
ArkApi::GetCommands()
/* Shortcut */
#define API_UTILS \
ArkApi::GetApiUtils()
/* Shortcut */
#define LOG \
Log::GetLog()