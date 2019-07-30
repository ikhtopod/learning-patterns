#include "run.h"

namespace AbstractFactory {

void Run() {
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

} // namespace AbstractFactory 
