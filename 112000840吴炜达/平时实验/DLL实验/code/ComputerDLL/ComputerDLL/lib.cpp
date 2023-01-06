/* ÎÄ¼þÃû£ºlib.cpp¡¡*/
#pragma once
#include "lib.h"
#include <windows.h>
#include <stdio.h>
#include <SDKDDKVer.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif


BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("\nprocess attach of dll");
		break;
	case DLL_THREAD_ATTACH:
		printf("\nthread attach of dll");
		break;
	case DLL_THREAD_DETACH:
		printf("\nthread detach of dll");
		break;
	case DLL_PROCESS_DETACH:
		printf("\nprocess detach of dll");
		break;
	}
	return TRUE;
}

