#pragma once
#include <string>
#include <memory>

class UserData
{
public:
	UserData();
	UserData(int id, const wchar_t* pName);
	UserData(const UserData& other);
	UserData& operator=(const UserData& other);
	~UserData();

	int getId() const;
	void setId(int id);
	const std::wstring & getName() const;

private:
	class Impl;
	std::unique_ptr<Impl> m_pImpl;
};