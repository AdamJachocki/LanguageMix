#pragma once
#include <string>
#include "library.h"
#include "UserData.h"
#include <memory>

class UserRepository
{
public:
	UserRepository();
	~UserRepository();

	int addUser(UserData& data);
	const UserData& getUserById(int id) const;

private:
	class Impl;
	std::unique_ptr<Impl> m_pImpl;
};