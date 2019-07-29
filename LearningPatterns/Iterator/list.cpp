#include "list.h"

namespace Iterator {


std::shared_ptr<MonsterIterator> Monsters::CreateIterator(const MonsterIteratorType& type) {
	switch (type) {
		case Iterator::MonsterIteratorType::ODD:
			return std::make_shared<OddIterator>(this);
		case Iterator::MonsterIteratorType::EVEN:
			return std::make_shared<EvenIterator>(this);
		case Iterator::MonsterIteratorType::LOOP:
			return std::make_shared<LoopIterator>(this);
		case Iterator::MonsterIteratorType::RANDOM:
			return std::make_shared<RandomIterator>(this);
		default:
			return std::shared_ptr<MonsterIterator> {};
	}
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
