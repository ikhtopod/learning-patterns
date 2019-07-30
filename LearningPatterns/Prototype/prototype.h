#pragma once

#ifndef PROTOTYPE_PROTOTYPE_H
#define PROTOTYPE_PROTOTYPE_H

#include <string>
#include <memory>

namespace Prototype {

template <typename Prototype>
class Cloneable { // Prototype
public:
	virtual std::shared_ptr<Prototype> Clone() = 0;
};


class Monster : public Cloneable<Monster> {
protected:
	float m_speedMoving;

public:
	Monster(const float& speedMoving);

	virtual float GetSpeedMoving() const final;
	virtual void SetSpeedMoving(const float& speedMoving) final;
};

class Zombie : public Monster {
public:
	Zombie(const float& speedMoving);
	Zombie(const Zombie& zombie);

	virtual std::shared_ptr<Monster> Clone() override;
};


class Skeleton : public Monster {
protected:
	int m_amountBones;

public:
	Skeleton(const float& speedMoving, const int& amountBones);
	Skeleton(const Skeleton& skeleton);

	virtual std::shared_ptr<Monster> Clone() override;

	int GetAmountBones() const;
	void SetAmountBones(const int& amountBones);
};


} // namespace Prototype

#endif // !PROTOTYPE_PROTOTYPE_H
