#pragma once
#include "stdafx.h"

#ifdef HOOKDLL_EXPORTS
#define HOOKDLL_API __declspec(dllexport)   
#else  
#define HOOKDLL_API __declspec(dllimport)   
#endif  

#define WM_KEYSTROKE (WM_USER + 101)

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
);


extern "C" HOOKDLL_API LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);

extern "C" HOOKDLL_API void InstallMouseHook(HWND hWndCaller);

extern "C" HOOKDLL_API void RemoveHooks(void);

extern "C" HOOKDLL_API void InstallTouchHook(HWND hWndCaller);
extern "C" HOOKDLL_API void RemoveTouchHook(void);
extern "C" HOOKDLL_API LRESULT CALLBACK TouchHookProc(int nCode, WPARAM wParam, LPARAM lParam);
