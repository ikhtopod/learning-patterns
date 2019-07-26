#pragma once

#ifndef ABSTRACTFACTORY_LEVEL_H
#define ABSTRACTFACTORY_LEVEL_H

#include <iostream>
#include <memory>

#include "level_factory.h"

namespace AbstractFactory {

enum class LevelType {
	FOREST, DESERT, UNDERGROUND_PRISON
};

class Level final {
private:
	LevelType m_levelType;
	std::shared_ptr<LevelFactory> m_levelFactory;

private:
	void InitLevelFactory();

public:
	Level(const LevelType& levelType);
	~Level();

	void Generate();
};

}// namespace AbstractFactory

#endif // !ABSTRACTFACTORY_LEVEL_H
