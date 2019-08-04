#pragma once

#ifndef ADAPTER_ADAPTER_H
#define ADAPTER_ADAPTER_H

#include <iostream>

namespace Adapter {

class Runnable { //client interface
public:
	virtual void Run() = 0;
};


class Moveable { // for service
public:
	virtual void Move() = 0;
	virtual void FastMoving() = 0;
};


class MovingCanRunning final : public Runnable { // Adapter
private:
	Moveable* const m_moveable;

public:
	MovingCanRunning(Moveable* const moveable);
	
	virtual void Run() override;
};


class MovingObject final : public Moveable { // Service
private:
	float m_movement = 7.0f;
	float m_fast = 2.0f;

public:
	virtual void Move() override;
	virtual void FastMoving() override;
};

} // namespace Adapter

#endif // !ADAPTER_ADAPTER_H
