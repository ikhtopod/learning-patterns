#include "level.h"

namespace AbstractFactory {

Level::Level(const LevelType& levelType) : m_levelType(levelType), m_levelFactory(nullptr) {
	InitLevelFactory();
}

Level::~Level() {
	m_levelFactory.reset();
	std::cout << "Level destroyed" << std::endl << std::endl;
}

void Level::InitLevelFactory() {
	switch (m_levelType) {
		case LevelType::FOREST:
			m_levelFactory = std::make_shared<ForestLevelFactory>();
			std::cout << "Level Forest" << std::endl;
			break;
		case LevelType::DESERT:
			m_levelFactory = std::make_shared<DesertLevelFactory>();
			std::cout << "Level Desert" << std::endl;
			break;
		case LevelType::UNDERGROUND_PRISON:
			m_levelFactory = std::make_shared<UndergroundPrisonLevelFactory>();
			std::cout << "Level Underground Prison" << std::endl;
			break;
	}
}

void Level::Generate() {
	// m_levelFactory->createWorld();  // for example
	// m_levelFactory->createEnvironment();  // for example
	m_levelFactory->CreateMonsters();
	std::cout << "Level generated" << std::endl;
}

}// namespace AbstractFactory
