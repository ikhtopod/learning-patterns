#include "iterator.h"

namespace Iterator {

MonsterIteratorException::MonsterIteratorException() : MonsterIteratorException("") {}

MonsterIteratorException::MonsterIteratorException(const char* const message) :
	std::exception(message) {}



ThroughStepIterator::ThroughStepIterator(const MonsterIterable* list, const size_t& defaultIndex) :
	m_defaultIndex(defaultIndex),
	m_currentIndex(m_defaultIndex),
	m_list(list) {}


Monster& ThroughStepIterator::CurrentItem() const {
	if (IsDone()) {
		throw MonsterIteratorException {};
	}

	return m_list->Get(m_currentIndex);
}

bool ThroughStepIterator::IsDone() const {
	return m_currentIndex >= m_list->Count();
}

void ThroughStepIterator::Reset() {
	m_currentIndex = m_defaultIndex;
}

void ThroughStepIterator::Next() {
	if (!IsDone()) {
		m_currentIndex += STEP_OF_ITERATION;
	}
}


OddIterator::OddIterator(const MonsterIterable* list) :
	ThroughStepIterator(list, DEFAULT_INDEX) {}


EvenIterator::EvenIterator(const MonsterIterable* list) :
	ThroughStepIterator(list, DEFAULT_INDEX) {}



LoopIterator::LoopIterator(const MonsterIterable* list) :
	m_currentIndex(DEFAULT_INDEX), m_list(list) {}

Monster& LoopIterator::CurrentItem() const {
	if (IsDone()) {
		throw MonsterIteratorException {};
	}

	return m_list->Get(m_currentIndex);
}

bool LoopIterator::IsDone() const {
	return m_currentIndex >= m_list->Count();
}

void LoopIterator::Reset() {
	m_currentIndex = DEFAULT_INDEX;
}

void LoopIterator::Next() {
	if (!IsDone()) {
		m_currentIndex += STEP_OF_ITERATION;

		if (IsDone()) {
			Reset();
		}
	} else {
		Reset();
	}
}


RandomIterator::RandomIterator(const MonsterIterable* list) :
	m_currentIndex(DEFAULT_INDEX), m_list(list) {}

Monster& RandomIterator::CurrentItem() const {
	if (IsDone()) {
		throw MonsterIteratorException {};
	}

	return m_list->Get(m_currentIndex);
}

bool RandomIterator::IsDone() const {
	return m_currentIndex >= m_list->Count();
}

void RandomIterator::Reset() {
	m_currentIndex = DEFAULT_INDEX;
}

void RandomIterator::Next() {
	if (m_list->Count() == 0) return;

	std::default_random_engine dre { RandomIterator::GetSeed() };
	std::uniform_int_distribution uid { size_t { 0 }, m_list->Count() - 1 };

	m_currentIndex = uid(dre);
}

uint32_t RandomIterator::GetSeed() {
	using namespace std::chrono;
	time_point<steady_clock> tp = steady_clock::now();
	uint32_t seed = static_cast<uint32_t>(tp.time_since_epoch().count());
	return seed;
}


} // namespace Iterator
