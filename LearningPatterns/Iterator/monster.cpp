#include "monster.h"

namespace Iterator {

Monster::Monster(const std::string& id) : m_id(id) {}

std::string Monster::GetId() const {
	return m_id;
}

Zombie::Zombie(const std::string& id) : Monster(id + TYPE) {}

Skeleton::Skeleton(const std::string& id) : Monster(id + TYPE) {}

} // namespace Iterator
