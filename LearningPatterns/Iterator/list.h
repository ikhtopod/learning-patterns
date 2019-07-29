#pragma once

#ifndef ITERATOR_LIST_H
#define ITERATOR_LIST_H

#include <vector>
#include <memory>

#include "monster.h"
#include "iterator.h"

namespace Iterator {

class MonsterAddable {
public:
	virtual void Add(const std::shared_ptr<Monster>& monster) = 0;
};


class Monsters : public MonsterIterable, public MonsterAddable {  // Concrete Aggregate
private:
	std::vector<std::shared_ptr<Monster>> m_monsters {};

public:
	virtual std::shared_ptr<MonsterIterator> CreateIterator() override;
	virtual size_t Count() const override;
	virtual Monster& Get(size_t index) const override;

	virtual void Add(const std::shared_ptr<Monster>& monster) override;
};

} // namespace Iterator

#endif // !ITERATOR_LIST_H
