#include "includes.h"
#include <API/ARK/Ark.h>
#include <macros.h>

DECLARE_HOOK(UseS3, bool, UPrimalLocalProfile*);
class Plugin
{
	static bool Hook_UseS3(UPrimalLocalProfile* _this)
	{
		return 1;
	}
};