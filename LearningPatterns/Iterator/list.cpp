#include "list.h"

namespace Iterator {


std::shared_ptr<MonsterIterator> Monsters::CreateIterator() {
	return std::make_shared<OddIterator>(this);
}

size_t Monsters::Count() const {
	return m_monsters.size();
}

Monster& Monsters::Get(size_t index) const {
	return *m_monsters.at(index);
}

void Monsters::Add(const std::shared_ptr<Monster>& monster) {
	m_monsters.push_back(monster);
}


} // namespace Iterator
