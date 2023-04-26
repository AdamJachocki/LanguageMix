#pragma once
#include <memory>
#include <string>
#include <vector>
#include "UserData.h"

class CompanyData
{
public:
	CompanyData(int id, wchar_t* pName);
	CompanyData(const CompanyData& other);
	~CompanyData();

	int getId() const;
	const std::wstring & getName() const;
	const std::vector<UserData> getUsers() const;

private:
	class Impl;
	std::unique_ptr<Impl> m_pImpl;

	void operator=(const CompanyData& other) {}
};