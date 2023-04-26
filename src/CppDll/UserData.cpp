#include "pch.h"
#include "UserData.h"

class UserData::Impl
{
public:
	Impl(int id, const wchar_t* pName)
	{
		m_id = id;
		m_name = pName;
	}

	Impl(const Impl * pOther)
	{
		assignFrom(pOther);
	}

	Impl& operator=(const Impl* pData)
	{
		assignFrom(pData);
		return *this;
	}

public:
	int m_id;
	std::wstring m_name;

private:
	void assignFrom(const Impl* pOther)
	{
		m_id = pOther->m_id;
		m_name = pOther->m_name;
	}
};

UserData::UserData()
{
	m_pImpl.reset(new Impl(0, L""));
}

UserData::UserData(int id, const wchar_t* pName)
{
	m_pImpl.reset(new Impl(id, pName));
}

UserData::UserData(const UserData& other)
{
	m_pImpl.reset(new Impl(other.m_pImpl.get()));
}

UserData& UserData::operator=(const UserData& other)
{
	*m_pImpl = other.m_pImpl.get();
	return *this;
}

UserData::~UserData()
{
	m_pImpl.reset(nullptr);
}

int UserData::getId() const
{
	return m_pImpl->m_id;
}

void UserData::setId(int id)
{
	m_pImpl->m_id = id;
}

const std::wstring & UserData::getName() const
{
	return m_pImpl->m_name;
}
