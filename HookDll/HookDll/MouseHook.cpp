// MouseHook.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MouseHook.h"
#include <stdio.h>


#pragma comment(linker, "/SECTION:.SHARED,RWS")
#pragma data_seg(".SHARED")
int iKeyCount = 0;
HWND g_hWnd = NULL;	        // Window handle
HHOOK g_hHook = NULL;		// Hook handle
#pragma data_seg()

HMODULE hInstance = 0;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hInstance = (HINSTANCE)hModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// Get module from address
HMODULE WINAPI ModuleFromAddress(PVOID pv)
{
	MEMORY_BASIC_INFORMATION mbi;
	if (::VirtualQuery(pv, &mbi, sizeof(mbi)) != 0)
	{
		return (HMODULE)mbi.AllocationBase;
	}
	else
	{
		return NULL;
	}
}

extern "C" LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode < 0 || nCode == HC_NOREMOVE)
		return ::CallNextHookEx(g_hHook, nCode, wParam, lParam);

	PostMessage(g_hWnd, WM_KEYSTROKE, wParam, lParam);
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

void InstallMouseHook(HWND hWndCaller)
{
	g_hWnd = hWndCaller;
	g_hHook = SetWindowsHookEx(WH_MOUSE, MouseHookProc, ModuleFromAddress(MouseHookProc), 0);
}

void RemoveHooks(void)
{
	UnhookWindowsHookEx(g_hHook);
	g_hHook = 0;
}
