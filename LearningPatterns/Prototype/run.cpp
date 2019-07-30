#include "run.h"

namespace Prototype {

void Run() {
	std::shared_ptr<Zombie> zombie = std::make_shared<Zombie>(1.2f);
	std::shared_ptr<Skeleton> skeleton = std::make_shared<Skeleton>(1.1f, 128);

	std::cout << "Zombie SpeedMoving: " << zombie->GetSpeedMoving() << std::endl;

	std::cout << "Skeleton SpeedMoving: " << skeleton->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton AmountBones: " << skeleton->GetAmountBones() << std::endl;
	std::cout << std::string().assign(25, '-') << std::endl;

	std::shared_ptr<Zombie> zombieClone = std::dynamic_pointer_cast<Zombie>(zombie->Clone());
	std::shared_ptr<Skeleton> skeletonClone = std::dynamic_pointer_cast<Skeleton>(skeleton->Clone());

	std::cout << "Zombie SpeedMoving: " << zombie->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton SpeedMoving: " << skeleton->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton AmountBones: " << skeleton->GetAmountBones() << std::endl << std::endl;

	std::cout << "ZombieClone SpeedMoving: " << zombieClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone SpeedMoving: " << skeletonClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone AmountBones: " << skeletonClone->GetAmountBones() << std::endl;
	std::cout << std::string().assign(25, '-') << std::endl;

	zombieClone->SetSpeedMoving(0.3f);
	skeletonClone->SetAmountBones(96);

	std::cout << "Zombie SpeedMoving: " << zombie->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton SpeedMoving: " << skeleton->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton AmountBones: " << skeleton->GetAmountBones() << std::endl << std::endl;

	std::cout << "ZombieClone SpeedMoving: " << zombieClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone SpeedMoving: " << skeletonClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone AmountBones: " << skeletonClone->GetAmountBones() << std::endl;
	std::cout << std::string().assign(25, '-') << std::endl;

	std::shared_ptr<Skeleton> skeletonCloneClone = std::dynamic_pointer_cast<Skeleton>(skeletonClone->Clone());

	std::cout << "Zombie SpeedMoving: " << zombie->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton SpeedMoving: " << skeleton->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton AmountBones: " << skeleton->GetAmountBones() << std::endl << std::endl;

	std::cout << "ZombieClone SpeedMoving: " << zombieClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone SpeedMoving: " << skeletonClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone AmountBones: " << skeletonClone->GetAmountBones() << std::endl << std::endl;

	std::cout << "SkeletonCloneClone SpeedMoving: " << skeletonCloneClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonCloneClone AmountBones: " << skeletonCloneClone->GetAmountBones() << std::endl;
	std::cout << std::string().assign(25, '-') << std::endl;

	skeletonClone->SetSpeedMoving(2.2f);
	skeletonCloneClone->SetSpeedMoving(0.2f);

	std::cout << "Zombie SpeedMoving: " << zombie->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton SpeedMoving: " << skeleton->GetSpeedMoving() << std::endl;
	std::cout << "Skeleton AmountBones: " << skeleton->GetAmountBones() << std::endl << std::endl;

	std::cout << "ZombieClone SpeedMoving: " << zombieClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone SpeedMoving: " << skeletonClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonClone AmountBones: " << skeletonClone->GetAmountBones() << std::endl << std::endl;

	std::cout << "SkeletonCloneClone SpeedMoving: " << skeletonCloneClone->GetSpeedMoving() << std::endl;
	std::cout << "SkeletonCloneClone AmountBones: " << skeletonCloneClone->GetAmountBones() << std::endl;
	std::cout << std::string().assign(25, '-') << std::endl;
}

}
