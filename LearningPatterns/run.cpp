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
		Monsters monsters {};
		monsters.Add(std::shared_ptr<Zombie> { new Zombie { "OneZ" } });
		monsters.Add(std::make_shared<Zombie>("TwoZ"));
		monsters.Add(std::make_shared<Skeleton>("OneS"));

		std::shared_ptr<MonsterIterator> M_OddIter = monsters.CreateIterator(MonsterIteratorType::ODD);
		std::shared_ptr<MonsterIterator> M_EvenIter = monsters.CreateIterator(MonsterIteratorType::EVEN);
		std::shared_ptr<MonsterIterator> M_LoopIter = monsters.CreateIterator(MonsterIteratorType::LOOP);
		std::shared_ptr<MonsterIterator> M_RandIter = monsters.CreateIterator(MonsterIteratorType::RANDOM);

		std::cout << "Odd Iterator:" << std::endl;
		for (; !M_OddIter->IsDone(); M_OddIter->Next()) {
			std::cout << M_OddIter->CurrentItem().GetId() << std::endl;
		}
		M_OddIter->Reset();
		std::cout << std::endl;

		std::cout << "Even Iterator:" << std::endl;
		for (; !M_EvenIter->IsDone(); M_EvenIter->Next()) {
			std::cout << M_EvenIter->CurrentItem().GetId() << std::endl;
		}
		M_EvenIter->Reset();
		std::cout << std::endl;

		std::cout << "Loop Iterator:" << std::endl;
		for (size_t counter = 0; !M_LoopIter->IsDone() && counter < 10; M_LoopIter->Next(), counter++) {
			std::cout << counter << ")" << M_LoopIter->CurrentItem().GetId() << std::endl;
		}
		M_LoopIter->Reset();
		std::cout << std::endl;

		std::cout << "Random Iterator:" << std::endl;
		for (size_t counter = 0; !M_RandIter->IsDone() && counter < 10; M_RandIter->Next(), counter++) {
			std::cout << counter << ")" << M_RandIter->CurrentItem().GetId() << std::endl;
		}
		M_RandIter->Reset();
		std::cout << std::endl;

	}
}
