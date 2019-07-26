#include "monster.h"

namespace AbstractFactory {

/* Monster */

Monster::Monster(const uint32_t& counter) : m_counter(counter) {
	std::cout << m_counter << ") ";
}

Monster::~Monster() {
	std::cout << "destroyed" << std::endl;
}

/* Zombie */

Zombie::Zombie(const uint32_t& counter) : Monster(counter) {
	std::cout << "Zombie ";
}

Zombie::~Zombie() {
	std::cout << "Zombie ";
}


ForestZombie::ForestZombie(const uint32_t& counter) : Zombie(counter) {
	std::cout << "Forest " << std::endl;
}

ForestZombie::~ForestZombie() {
	std::cout << "Forest ";
}


DesertZombie::DesertZombie(const uint32_t& counter) : Zombie(counter) {
	std::cout << "Desert " << std::endl;
}

DesertZombie::~DesertZombie() {
	std::cout << "Desert ";
}


UndergroundPrisonZombie::UndergroundPrisonZombie(const uint32_t& counter) : Zombie(counter) {
	std::cout << "Underground Prison " << std::endl;
}

UndergroundPrisonZombie::~UndergroundPrisonZombie() {
	std::cout << "Underground Prison ";
}

/* Skeleton */

Skeleton::Skeleton(const uint32_t& counter) : Monster(counter) {
	std::cout << "Skeleton ";
}

Skeleton::~Skeleton() {
	std::cout << "Skeleton ";
}


ForestSkeleton::ForestSkeleton(const uint32_t& counter) : Skeleton(counter) {
	std::cout << "Forest " << std::endl;
}

ForestSkeleton::~ForestSkeleton() {
	std::cout << "Forest ";
}


DesertSkeleton::DesertSkeleton(const uint32_t& counter) : Skeleton(counter) {
	std::cout << "Desert " << std::endl;
}

DesertSkeleton::~DesertSkeleton() {
	std::cout << "Desert ";
}


UndergroundPrisonSkeleton::UndergroundPrisonSkeleton(const uint32_t& counter) : Skeleton(counter) {
	std::cout << "Underground Prison " << std::endl;
}

UndergroundPrisonSkeleton::~UndergroundPrisonSkeleton() {
	std::cout << "Underground Prison ";
}

/* Spider */

Spider::Spider(const uint32_t& counter) : Monster(counter) {
	std::cout << "Spider ";
}

Spider::~Spider() {
	std::cout << "Spider ";
}


ForestSpider::ForestSpider(const uint32_t& counter) : Spider(counter) {
	std::cout << "Forest " << std::endl;
}

ForestSpider::~ForestSpider() {
	std::cout << "Forest ";
}


DesertSpider::DesertSpider(const uint32_t& counter) : Spider(counter) {
	std::cout << "Desert " << std::endl;
}

DesertSpider::~DesertSpider() {
	std::cout << "Desert ";
}


UndergroundPrisonSpider::UndergroundPrisonSpider(const uint32_t& counter) : Spider(counter) {
	std::cout << "Underground Prison " << std::endl;
}

UndergroundPrisonSpider::~UndergroundPrisonSpider() {
	std::cout << "Underground Prison ";
}

}// namespace AbstractFactory
