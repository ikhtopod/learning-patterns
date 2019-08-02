#include "run.h"

namespace State {

void Run() {
	CameraSwitcher cs {};

	std::cout << "Camera State: " << (cs.GetState() == CameraState::TARGET ? "Target" : "Free") << std::endl;
	cs.GetCamera()->Move();
	cs.GetCamera()->Look();

	cs.Switch();

	std::cout << "Camera State: " << (cs.GetState() == CameraState::TARGET ? "Target" : "Free") << std::endl;
	cs.GetCamera()->Move();
	cs.GetCamera()->Look();

	cs.Switch();

	std::cout << "Camera State: " << (cs.GetState() == CameraState::TARGET ? "Target" : "Free") << std::endl;
	cs.GetCamera()->Move();
	cs.GetCamera()->Look();
}

} // namespace State
