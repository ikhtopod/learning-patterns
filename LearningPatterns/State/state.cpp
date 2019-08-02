#include "state.h"

namespace State {


/* TargetCamera */

void TargetCamera::Move() {
	std::cout << "TargetCamera is moves" << std::endl;
}

void TargetCamera::Look() {
	std::cout << "TargetCamera is looking" << std::endl;
}


/* FreeCamera */

void FreeCamera::Move() {
	std::cout << "FreeCamera is moves" << std::endl;
}

void FreeCamera::Look() {
	std::cout << "FreeCamera is looking" << std::endl;
}


/* CameraSwitcher */

const CameraState CameraSwitcher::DEFAULT_STATE = CameraState::TARGET;

CameraSwitcher::CameraSwitcher() :
	CameraSwitcher(CameraSwitcher::DEFAULT_STATE) {}

CameraSwitcher::CameraSwitcher(const CameraState& state) :
	m_state(state) {}

CameraState CameraSwitcher::GetState() const {
	return m_state;
}

const std::shared_ptr<Camera> CameraSwitcher::GetCamera() const {
	return m_cameras.at(m_state);
}

void CameraSwitcher::Switch() {
	switch (m_state) {
		case CameraState::TARGET:
			m_state = CameraState::FREE;
			break;
		case CameraState::FREE:
			m_state = CameraState::TARGET;
			break;
		default:
			m_state = CameraSwitcher::DEFAULT_STATE;
			break;
	}
}


} // namespace State
