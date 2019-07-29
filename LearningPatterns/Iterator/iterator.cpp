#include "iterator.h"

namespace Iterator {


OddIteratorException::OddIteratorException(const char* const message) :
	std::exception(message) {}


OddIterator::OddIterator(const MonsterIterable* list) :
	m_currentIndex(OddIterator::DEFAULT_INDEX),
	m_list(list) {}

OddIterator::~OddIterator() {
	m_list = nullptr;
}


Monster& OddIterator::CurrentItem() const {
	if (IsDone()) {
		throw OddIteratorException { "OddIterator IsDone" };
	}

	return m_list->Get(m_currentIndex);
}

bool OddIterator::IsDone() const {
	return m_currentIndex >= m_list->Count();
}

void OddIterator::Reset() {
	m_currentIndex = DEFAULT_INDEX;
}

void OddIterator::Next() {
	if (!IsDone()) {
		m_currentIndex += STEP_OF_ITERATION;
	}
}


} // namespace Iterator
