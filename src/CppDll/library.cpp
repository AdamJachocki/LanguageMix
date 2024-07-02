#include "pch.h"
#include "library.h"
//#include "UserRepository.h"
#include <combaseapi.h>
#include <strsafe.h>
#include <string>
#include <filesystem>


DLL_EXPORT int add(int a, int b)
{	
	return a + b;
}

DLL_EXPORT size_t getStrLen(const wchar_t* pStr)
{
	std::wstring str(pStr);
	return str.size();
}

DLL_EXPORT size_t __stdcall getStrLenA(const char* pStr)
{
	std::string str(pStr);
	return str.size();
}

DLL_EXPORT wchar_t* getInfo()
{
	return _wcsdup(L"𠝹");  //(L"Jestem wywołany z C++!");	
}

DLL_EXPORT void freeInfo(wchar_t* pData)
{
	delete pData;
}

DLL_EXPORT wchar_t* __stdcall getInfoWithCom()
{
	std::wstring str = L"𠝹"; //L"Cześć, jestem z COM";
	size_t allocSize = str.size() * 2 + 2;
	STRSAFE_LPWSTR result = (STRSAFE_LPWSTR)CoTaskMemAlloc(allocSize);
	StringCchCopy(result, allocSize, str.c_str());

	return (wchar_t*)result;
}

DLL_EXPORT BSTR __stdcall getInfoWithBstr()
{
	return SysAllocString(L"A tak działa BSTR");
}

DLL_EXPORT void getInfo2(wchar_t* pData, int strLen)
{
	ZeroMemory(pData, strLen * 2);
	std::wstring result = L"Można i tak...";
	result = result.substr(0, strLen);
	std::copy(result.begin(), result.end(), pData);
}

DLL_EXPORT int __stdcall getInfo3(wchar_t* pData, int strLen)
{
	std::wstring str = L"A to jest string o nieznanej długości";

	if (pData == nullptr)
		return str.size();

	ZeroMemory(pData, strLen * 2);
	str = str.substr(0, strLen);
	std::copy(str.begin(), str.end(), pData);
	return 0;
}

DLL_EXPORT void __stdcall getInfo4(BSTR& data)
{
	data = SysAllocString(L"Dzień dobry, jak się masz?");
}

DLL_EXPORT Point3d __stdcall getPoint3d()
{
	return { 1.5f, 2.25f, 3.3f };
}

DLL_EXPORT void __stdcall updatePoint3d(Point3d& point)
{
	point.x += 1.0f;
	point.y += 1.0f;
	point.z += 1.0f;
}

DLL_EXPORT FileInfo __stdcall getFileInfo(const wchar_t* pFilePath)
{
	std::filesystem::path path{ pFilePath };

	FileInfo result = { 0 };
	result.fileSize = std::filesystem::file_size(path);
	
	//std::wstring filePath = pFilePath;
	//CopyMemory(result.fileName, pFilePath, filePath.size() * sizeof(wchar_t));
	result.fileName = SysAllocString(pFilePath);

	return result;
}
