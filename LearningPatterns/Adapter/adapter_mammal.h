#pragma once

#ifndef ADAPTER_ADAPTER_MAMMAL_H
#define ADAPTER_ADAPTER_MAMMAL_H

#include <iostream>

namespace AdapterMammal {

class Mammal {};

class Human : public Mammal {
public:
	void Walk();
};

class Hawk : public Mammal {
public:
	void Fly();
};

class Python : public Mammal {
public:
	void Crawl();
};


class Moveable {
public:
	virtual void Move() = 0;
};

class HumanMoveAdapter final : public Moveable {
private:
	Human* m_human;

public:
	HumanMoveAdapter(Human* const human);

	virtual void Move() override;
};

class HawkMoveAdapter final : public Moveable {
private:
	Hawk* m_hawk;

public:
	HawkMoveAdapter(Hawk* const hawk);

	virtual void Move() override;
};

class PythonMoveAdapter final : public Moveable {
private:
	Python* m_python;

public:
	PythonMoveAdapter(Python* const python);

	virtual void Move() override;
};



} // namespace AdapterMammal

#endif // !ADAPTER_ADAPTER_MAMMAL_H
