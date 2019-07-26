#include "level_factory.h"

namespace AbstractFactory {

/* ForestLevelFactory */

void ForestLevelFactory::CreateForestZombie() {
	for (uint32_t i = 0; i < 3; ++i)
		m_zombie.push_back(std::make_shared<ForestZombie>(i));
}

void ForestLevelFactory::CreateForestSpiders() {
	for (uint32_t i = 0; i < 4; ++i)
		m_spiders.push_back(std::make_shared<ForestSpider>(i));
}

void ForestLevelFactory::CreateMonsters() {
	CreateForestZombie();
	CreateForestSpiders();

	std::cout << "Created Forest monsters" << std::endl;
}

/* DesertLevelFactory */

void DesertLevelFactory::CreateDesertSkeletons() {
	for (uint32_t i = 0; i < 2; ++i)
		m_skeletons.push_back(std::make_shared<DesertSkeleton>(i));
}

void DesertLevelFactory::CreateDesertSpiders() {
	for (uint32_t i = 0; i < 1; ++i)
		m_spiders.push_back(std::make_shared<DesertSpider>(i));
}

void DesertLevelFactory::CreateMonsters() {
	CreateDesertSkeletons();
	CreateDesertSpiders();

	std::cout << "Created Desert monsters" << std::endl;
}

/* UndergroundPrisonLevelFactory */

void UndergroundPrisonLevelFactory::CreateUndergroundPrisonZombie() {
	for (uint32_t i = 0; i < 4; ++i)
		m_zombie.push_back(std::make_shared<UndergroundPrisonZombie>(i));
}

void UndergroundPrisonLevelFactory::CreateUndergroundPrisonSkeletons() {
	for (uint32_t i = 0; i < 3; ++i)
		m_skeletons.push_back(std::make_shared<UndergroundPrisonSkeleton>(i));
}

void UndergroundPrisonLevelFactory::CreateUndergroundPrisonSpiders() {
	for (uint32_t i = 0; i < 1; ++i)
		m_spiders.push_back(std::make_shared<UndergroundPrisonSpider>(i));
}

void UndergroundPrisonLevelFactory::CreateMonsters() {
	CreateUndergroundPrisonZombie();
	CreateUndergroundPrisonSkeletons();
	CreateUndergroundPrisonSpiders();

	std::cout << "Created Underground Prison monsters" << std::endl;
}

}// namespace AbstractFactory
