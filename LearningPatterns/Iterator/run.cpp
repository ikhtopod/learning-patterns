#include "run.h"

namespace Iterator {

void Run() {
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