#pragma once

#ifndef ABSTRACTFACTORY_LEVEL_FACTORY_H
#define ABSTRACTFACTORY_LEVEL_FACTORY_H

#include <iostream>
#include <vector>
#include <memory>

#include "monster.h"

namespace AbstractFactory {

class LevelFactory {
public:
	virtual void CreateMonsters() = 0;
};


class ForestLevelFactory final : public LevelFactory {
private:
	std::vector<std::shared_ptr<Zombie>> m_zombie {};
	std::vector<std::shared_ptr<Spider>> m_spiders {};

private:
	void CreateForestZombie();
	void CreateForestSpiders();

public:
	virtual void CreateMonsters() override;
};


class DesertLevelFactory final : public LevelFactory {
private:
	std::vector<std::shared_ptr<Skeleton>> m_skeletons {};
	std::vector<std::shared_ptr<Spider>> m_spiders {};

private:
	void CreateDesertSkeletons();
	void CreateDesertSpiders();

public:
	virtual void CreateMonsters() override;
};


class UndergroundPrisonLevelFactory final : public LevelFactory {
private:
	std::vector<std::shared_ptr<Zombie>> m_zombie {};
	std::vector<std::shared_ptr<Skeleton>> m_skeletons {};
	std::vector<std::shared_ptr<Spider>> m_spiders {};

private:
	void CreateUndergroundPrisonZombie();
	void CreateUndergroundPrisonSkeletons();
	void CreateUndergroundPrisonSpiders();

public:
	virtual void CreateMonsters() override;
};


}// namespace AbstractFactory

#endif // !ABSTRACTFACTORY_LEVEL_FACTORY_H
