#pragma once
#include <WTypes.h>
#include "Point3d.h"
#include "FileInfo.h"

#ifdef CPPDLL_EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif


extern "C"
{
	DLL_EXPORT int __stdcall add(int a, int b);
	DLL_EXPORT size_t __stdcall getStrLen(const wchar_t* pStr);
	DLL_EXPORT size_t __stdcall getStrLenA(const char* pStr);

	DLL_EXPORT wchar_t* __stdcall  getInfo();
	DLL_EXPORT void __stdcall freeInfo(wchar_t* pData);
	DLL_EXPORT wchar_t* __stdcall getInfoWithCom();
	DLL_EXPORT BSTR __stdcall getInfoWithBstr();
	DLL_EXPORT void __stdcall getInfo2(wchar_t* pData, int strLen);
	DLL_EXPORT int __stdcall getInfo3(wchar_t* pData, int strLen);

	DLL_EXPORT void __stdcall getInfo4(BSTR& data);

	DLL_EXPORT int * __stdcall getIntArray();
	DLL_EXPORT void __stdcall getIntArrayAsParam(int data[]);

	DLL_EXPORT Point3d __stdcall getPoint3d();
	DLL_EXPORT void __stdcall updatePoint3d(Point3d& point);

	DLL_EXPORT FileInfo __stdcall getFileInfo(const wchar_t* pFilePath);
}