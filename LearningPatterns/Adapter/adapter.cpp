#include "adapter.h"

namespace Adapter {

MovingCanRunning::MovingCanRunning(Moveable* const moveable) : m_moveable(moveable) {}

void MovingCanRunning::Run() {
	return m_moveable->FastMoving();
}

void MovingObject::Move() {
	std::cout << "I am moving at speed " << m_movement << std::endl;
}

void MovingObject::FastMoving() {
	float fastMovement = m_fast * m_movement;
	std::cout << "I am fast moving at speed " << fastMovement << std::endl;
}

} // namespace Adapter
