#include "pch.h"
#include "library.h"
#include "UserRepository.h"
#include <combaseapi.h>
#include <strsafe.h>

class LibImpl
{
public:
	LibImpl()
	{
		m_pUserRepo.reset(new UserRepository());
	}

	~LibImpl()
	{
		m_pUserRepo.reset(nullptr);
	}

	bool addUser(const UserInfo& data)
	{
		UserData ud(data.m_id, data.p_name);
		m_pUserRepo->addUser(ud);
		return true;
	}

	//const UserInfo & getUser(int id)
	//{
	//	try
	//	{
	//		const UserData& data = m_userRepo.getUserById(id);
	//		UserInfo result;
	//		result.m_id = data.getId();
	//		//result.p_name = data.getName().c_str();
	//	}
	//}

	bool addCompany(const CompanyInfo& data)
	{
		//m_companies[data.m_id] = data;
		return true;
	}

private:
	std::unique_ptr<UserRepository> m_pUserRepo;
};


static LibImpl m_impl;

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
	return _wcsdup(L"Jestem wywo³any z C++!");	
}

DLL_EXPORT void freeInfo(wchar_t* pData)
{
	delete pData;
}

DLL_EXPORT wchar_t* __stdcall getInfoWithCom()
{
	std::wstring str = L"Czeœæ, jestem z COM";
	size_t allocSize = str.size() * 2 + 2;
	STRSAFE_LPWSTR result = (STRSAFE_LPWSTR)CoTaskMemAlloc(allocSize);
	StringCchCopy(result, allocSize, str.c_str());

	return (wchar_t*)result;
}

DLL_EXPORT BSTR __stdcall getInfoWithBstr()
{
	return SysAllocString(L"A tak dzia³a BSTR");
}

DLL_EXPORT void getInfo2(wchar_t* pData, int strLen)
{
	ZeroMemory(pData, strLen * 2);
	std::wstring result = L"Mo¿na i tak...";
	result = result.substr(0, strLen);
	std::copy(result.begin(), result.end(), pData);
}

DLL_EXPORT int __stdcall getInfo3(wchar_t* pData, int strLen)
{
	std::wstring str = L"A to jest string o nieznanej d³ugoœci";

	if (pData == nullptr)
		return str.size();

	ZeroMemory(pData, strLen * 2);
	str = str.substr(0, strLen);
	std::copy(str.begin(), str.end(), pData);
	return 0;
}

DLL_EXPORT void __stdcall getInfo4(BSTR& data)
{
	data = SysAllocString(L"Dzieñ dobry, jak siê masz?");
}

DLL_EXPORT bool addUser(const UserInfo& data)
{
	return m_impl.addUser(data);
}

DLL_EXPORT bool addCompany(const CompanyInfo& data)
{
	return m_impl.addCompany(data);
}

//DLL_EXPORT const UserInfo& getUser(int id)
//{
//	return m_impl.getUser(id);
//}

DLL_EXPORT void getUsers(UserInfo* pUsers)
{
	//return DLL_EXPORT void();
}
