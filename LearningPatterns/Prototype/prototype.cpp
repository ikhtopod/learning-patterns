#include "prototype.h"

namespace Prototype {

Monster::Monster(const float& speedMoving) : m_speedMoving(speedMoving) {}

float Monster::GetSpeedMoving() const {
	return m_speedMoving;
}

void Monster::SetSpeedMoving(const float& speedMoving) {
	m_speedMoving = speedMoving;
}


Zombie::Zombie(const float& speedMoving) : Monster(speedMoving) {}

Zombie::Zombie(const Zombie& zombie) : Zombie(zombie.m_speedMoving) {}

std::shared_ptr<Monster> Zombie::Clone() {
	return std::make_shared<Zombie>(*this);
}


Skeleton::Skeleton(const float& speedMoving, const int& amountBones) :
	Monster(speedMoving), m_amountBones(amountBones) {}

Skeleton::Skeleton(const Skeleton& skeleton) :
	Skeleton(skeleton.m_speedMoving, skeleton.m_amountBones) {}

std::shared_ptr<Monster> Skeleton::Clone() {
	return std::shared_ptr<Skeleton> { new Skeleton { *this } };
}

int Skeleton::GetAmountBones() const {
	return m_amountBones;
}

void Skeleton::SetAmountBones(const int& amountBones) {
	m_amountBones = amountBones;
}

} // namespace Prototype
