#include "pch.h"
#include "UserRepository.h"
#include <unordered_map>

class UserRepository::Impl
{
public:
	Impl()
	{

	}

	int addUser(UserData& data)
	{
		if (data.getId() <= 0)
			data.setId(m_maxId + 1);

		m_users[data.getId()] = data;
		m_maxId++;

		return data.getId();
	}

	const UserData& getUserById(int id) const
	{
		return m_users.at(id);
	}

private:
	int m_maxId;
	std::unordered_map<int, UserData> m_users;
};

UserRepository::UserRepository()
{
	m_pImpl.reset(new Impl());
}

UserRepository::~UserRepository() = default;

int UserRepository::addUser(UserData& data)
{
	return m_pImpl->addUser(data);
}

const UserData& UserRepository::getUserById(int id) const
{
	return m_pImpl->getUserById(id);
}
