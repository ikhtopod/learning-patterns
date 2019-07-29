#pragma once

#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

#include "monster.h"

#include <memory>
#include <exception>

namespace Iterator {

enum class MonsterIteratorType {
	ODD, EVEN, LOOP, RANDOM
};

class MonsterIterator { // Iterator
public:
	virtual Monster& CurrentItem() const = 0;
	virtual bool IsDone() const = 0;
	virtual void Reset() = 0;
	virtual void Next() = 0;
};


class MonsterIterable { // Aggregate
public:
	virtual std::shared_ptr<MonsterIterator> CreateIterator() = 0;

	virtual size_t Count() const = 0;
	virtual Monster& Get(size_t index) const = 0;
};


class OddIteratorException : public std::exception {
public:
	explicit OddIteratorException(const char* const message);
};


class OddIterator : public MonsterIterator { // Concrete Iterator
private:
	inline static const size_t DEFAULT_INDEX { 1 };
	inline static const size_t STEP_OF_ITERATION { 2 };

private:
	size_t m_currentIndex;
	const MonsterIterable* m_list;

public:
	OddIterator(const MonsterIterable* list);
	virtual ~OddIterator();

	virtual Monster& CurrentItem() const override;
	virtual bool IsDone() const override;
	virtual void Reset() override;
	virtual void Next() override;

};


} // namespace Iterator

#endif // !ITERATOR_ITERATOR_H
