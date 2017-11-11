// dllmain.cpp: реализация DllMain.

#include "stdafx.h"
#include "resource.h"
#include "DriveEx_i.h"
#include "dllmain.h"

CDriveExModule _AtlModule;

// Точка входа DLL
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
