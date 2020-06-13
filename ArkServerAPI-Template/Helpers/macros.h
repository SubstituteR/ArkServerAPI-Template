/**
 * Some macros to help new users.
 * These should also be useful to experienced users
 * as it should help in keeping names consistent.
 *
 */
#include <API/ARK/Ark.h>

/* Macro to add a hook easily. */
#define AddHook(functionName, hookName) \
ArkApi::GetHooks().SetHook(functionName, &Hook_ ## hookName, &hookName ## _original);
/* Macro to remove a hook easily. */
#define RemoveHook(functionName, hookName) \
ArkApi::GetHooks().DisableHook(functionName, &Hook_ ## hookName);
/* Shortcut */
#define Hooks \
ArkApi::GetHooks()
/* Shortcut */
#define Commands \
ArkApi::GetCommands()
/* Shortcut */
#define ApiUtils \
ArkApi::GetApiUtils()