#include "run.h"

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

void RunComposite() {
	using namespace Composite;

	{
		Bar bar {};
		Order order_01 {};

		order_01.AddPrice(std::make_shared<Coffee>(88.0));

		std::shared_ptr<SolidFood> meatWithTomatoAndSpices = std::make_shared<SolidFood>();
		meatWithTomatoAndSpices->AddComponent(std::make_shared<Meat>(256.0));
		meatWithTomatoAndSpices->AddComponent(std::make_shared<Tomato>(25.0));
		meatWithTomatoAndSpices->AddComponent(std::make_shared<Salt>(0.1));
		meatWithTomatoAndSpices->AddComponent(std::make_shared<Pepper>(0.1));
		order_01.AddPrice(meatWithTomatoAndSpices);

		bar.AddOrder(order_01);

		std::cout <<
			"Coffee(88.0) + SolidFood(Meat(256.0) + Tomato(25.0) + Salt(0.1) + Pepper(0.1)) = " <<
			(88.0 + 256.0 + 25.0 + 0.1 + 0.1) << std::endl <<
			"Composite result = " << bar.GetLast().GetPrices() << std::endl;
	}
}

void RunIterator() {
	using namespace Iterator;

	{
		// MonsterList monsters {};
		// monsters.Add(std::shared_ptr<Zombie> { new Zombie { "OneZ" } });
		// monsters.Add(std::make_shared<Zombie>("TwoZ"));
		// monsters.Add(std::make_shared<Skeleton>("OneS"));
	}
}
