#include "run.h"

namespace Adapter {

void Run() {
	{
		MovingObject* movingObject = new MovingObject {};

		std::cout << "MovingObject:" << std::endl;
		movingObject->Move();
		movingObject->FastMoving();

		Runnable* runnable = new MovingCanRunning { movingObject };
		std::cout << "Runnable:" << std::endl;
		runnable->Run();

		delete runnable;
		delete movingObject;
	}

	std::cout << "***" << "\nAdapterMammal example:" << std::endl;

	{
		using namespace AdapterMammal;

		Human* human = new Human {};
		Hawk* hawk = new Hawk {};
		Python* python = new Python {};

		AdapterMammal::Moveable* moveables[] {
			new HumanMoveAdapter { human },
			new HawkMoveAdapter { hawk },
			new PythonMoveAdapter { python },
		};

		for (auto& moveable : moveables) {
			moveable->Move();
			delete moveable;
		}

		delete human;
		delete hawk;
		delete python;
	}
}

} // namespace Adapter
