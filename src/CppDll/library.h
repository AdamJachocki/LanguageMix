#pragma once
#include <WTypes.h>

#ifdef CPPDLL_EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif


extern "C"
{
	struct UserInfo
	{
		int m_id;
		wchar_t* p_name;
	};

	struct CompanyInfo
	{
		int m_id;
		wchar_t* p_name;
		UserInfo* p_users;
	};

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

	DLL_EXPORT bool __stdcall addUser(const UserInfo& data);
	DLL_EXPORT bool __stdcall addCompany(const CompanyInfo& data);
	//DLL_EXPORT const UserInfo& getUser(int id);
	DLL_EXPORT void __stdcall getUsers(UserInfo* pUsers);
}