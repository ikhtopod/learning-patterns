#include "run.h"

namespace Adapter {

void Run() {
	MovingObject* movingObject = new MovingObject {};

	std::cout << "MovingObject:" << std::endl;
	movingObject->Move();
	movingObject->FastMoving();

	Runnable* runnable = new MovingCanRunning { movingObject };
	std::cout << "Runnable:" << std::endl;
	runnable->Run();

	delete movingObject;
	delete runnable;
}

} // namespace Adapter
