#include "pch.h"
#include "CompanyData.h"

class CompanyData::Impl
{
public:
	Impl(int id, wchar_t* pName)
	{
		m_id = id;
		m_name = pName;
	}

	Impl(const Impl* pOther)
	{
		m_id = pOther->m_id;
		m_name = pOther->m_name.c_str();
	}

public:
	int m_id;
	std::wstring m_name;
	std::vector<UserData> m_users;
};

CompanyData::CompanyData(int id, wchar_t* pName)
{
	m_pImpl.reset(new Impl(id, pName));
}

CompanyData::CompanyData(const CompanyData& other)
{
	m_pImpl.reset(new Impl(other.m_pImpl.get()));
}

CompanyData::~CompanyData()
{
	m_pImpl.reset(nullptr);
}

int CompanyData::getId() const
{
	return m_pImpl->m_id;
}

const std::wstring& CompanyData::getName() const
{
	return m_pImpl->m_name;
}

const std::vector<UserData> CompanyData::getUsers() const
{
	return m_pImpl->m_users;
}
