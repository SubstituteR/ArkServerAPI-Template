/*                             READ ME
*
*   This is the Windows API code for loading and unloading the DLL.
*   You should -not- have to change this at all.
*/
#include "includes.h"
#include "init.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        return Load();
    case DLL_PROCESS_DETACH:
        return Unload();
    }
    return FALSE; //Nothing happened!
}