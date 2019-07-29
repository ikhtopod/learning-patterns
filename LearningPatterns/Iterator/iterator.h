#pragma once

#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

#include "monster.h"

#include <memory>
#include <chrono>
#include <random>
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
	virtual std::shared_ptr<MonsterIterator> CreateIterator(const MonsterIteratorType& type) = 0;

	virtual size_t Count() const = 0;
	virtual Monster& Get(size_t index) const = 0;
};


class MonsterIteratorException : public std::exception {
public:
	explicit MonsterIteratorException();
	explicit MonsterIteratorException(const char* const message);
};


class ThroughStepIterator : public MonsterIterator {
protected:
	inline static const size_t STEP_OF_ITERATION { 2 };

private:
	const size_t m_defaultIndex;
	const MonsterIterable* m_list;

	size_t m_currentIndex;

protected:
	ThroughStepIterator(const MonsterIterable* list, const size_t& defaultIndex);

public:
	virtual Monster& CurrentItem() const override;
	virtual bool IsDone() const override;
	virtual void Reset() override;
	virtual void Next() override;
};


class OddIterator : public ThroughStepIterator { // Concrete Iterator
private:
	inline static const size_t DEFAULT_INDEX { 1 };

public:
	OddIterator(const MonsterIterable* list);
};

class EvenIterator : public ThroughStepIterator { // Concrete Iterator
private:
	inline static const size_t DEFAULT_INDEX { 0 };

public:
	EvenIterator(const MonsterIterable* list);
};


class LoopIterator : public MonsterIterator {
protected:
	inline static const size_t DEFAULT_INDEX { 0 };
	inline static const size_t STEP_OF_ITERATION { 1 };

private:
	const MonsterIterable* m_list;
	size_t m_currentIndex;

public:
	LoopIterator(const MonsterIterable* list);

	virtual Monster& CurrentItem() const override;
	virtual bool IsDone() const override;
	virtual void Reset() override;
	virtual void Next() override;
};



class RandomIterator : public MonsterIterator {
protected:
	inline static const size_t DEFAULT_INDEX { 0 };

private:
	const MonsterIterable* m_list;
	size_t m_currentIndex;

private:
	static uint32_t GetSeed();

public:
	RandomIterator(const MonsterIterable* list);

	virtual Monster& CurrentItem() const override;
	virtual bool IsDone() const override;
	virtual void Reset() override;
	virtual void Next() override;
};


} // namespace Iterator

#endif // !ITERATOR_ITERATOR_H
