#pragma once

#ifndef ABSTRACTFACTORY_MONSTER_H
#define ABSTRACTFACTORY_MONSTER_H

#include <iostream>

namespace AbstractFactory {

/* Monster */

class Monster {
protected:
	uint32_t m_counter = 0;

public:
	Monster(const uint32_t& counter);
	virtual ~Monster();
};

/* Zombie */

class Zombie : public Monster {
public:
	Zombie(const uint32_t& counter);
	virtual ~Zombie();
};

class ForestZombie final : public Zombie {
public:
	ForestZombie(const uint32_t& counter);
	virtual ~ForestZombie();
};

class DesertZombie final : public Zombie {
public:
	DesertZombie(const uint32_t& counter);
	virtual ~DesertZombie();
};

class UndergroundPrisonZombie final : public Zombie {
public:
	UndergroundPrisonZombie(const uint32_t& counter);
	virtual ~UndergroundPrisonZombie();
};

/* Skeleton */

class Skeleton : public Monster {
public:
	Skeleton(const uint32_t& counter);
	virtual ~Skeleton();
};

class ForestSkeleton final : public Skeleton {
public:
	ForestSkeleton(const uint32_t& counter);
	virtual ~ForestSkeleton();
};

class DesertSkeleton final : public Skeleton {
public:
	DesertSkeleton(const uint32_t& counter);
	virtual ~DesertSkeleton();
};

class UndergroundPrisonSkeleton final : public Skeleton {
public:
	UndergroundPrisonSkeleton(const uint32_t& counter);
	virtual ~UndergroundPrisonSkeleton();
};

/* Spider */

class Spider : public Monster {
public:
	Spider(const uint32_t& counter);
	virtual ~Spider();
};

class ForestSpider final : public Spider {
public:
	ForestSpider(const uint32_t& counter);
	virtual ~ForestSpider();
};

class DesertSpider final : public Spider {
public:
	DesertSpider(const uint32_t& counter);
	virtual ~DesertSpider();
};

class UndergroundPrisonSpider final : public Spider {
public:
	UndergroundPrisonSpider(const uint32_t& counter);
	virtual ~UndergroundPrisonSpider();
};

}// namespace AbstractFactory

#endif // !ABSTRACTFACTORY_MONSTER_H
