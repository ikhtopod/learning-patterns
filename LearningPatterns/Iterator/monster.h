#pragma once

#ifndef ITERATOR_MONSTER_H
#define ITERATOR_MONSTER_H

#include <string>
#include <memory>

namespace Iterator {

class Monster {
private:
	std::string m_id;

protected:
	Monster(const std::string& id);

public:
	std::string GetId() const;
};

class Zombie : public Monster {
private:
	inline static const std::string TYPE { "_Zombie" };

public:
	Zombie(const std::string& id);
};

class Skeleton : public Monster {
private:
	inline static const std::string TYPE { "_Skeleton" };

public:
	Skeleton(const std::string& id);
};

} // namespace Iterator

#endif // !ITERATOR_MONSTER_H
