#include <iostream>

#include "AbstractFactory/level.h"

void RunAbstractFactory() {
	using namespace AbstractFactory;

	{
		Level level1 { LevelType::FOREST };
		level1.Generate();
	}

	{
		Level level2 { LevelType::DESERT };
		level2.Generate();
	}

	{
		Level level3 { LevelType::UNDERGROUND_PRISON };
		level3.Generate();
	}
}

int main() {
	RunAbstractFactory();

	return 0;
}
