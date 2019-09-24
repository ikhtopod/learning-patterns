#include "run.h"

namespace Singleton {

void Run() {
	new PlayerManager {}; // instantiating
	
	std::cout <<
		"Player Name: " << PlayerManager::GetInstance()->GetName() << std::endl <<
		"Player Can Moving: " << std::boolalpha << PlayerManager::GetInstance()->CanMoving() << std::endl <<
		"Player Speed: " << PlayerManager::GetInstance()->CurrentSpeed();

	// delete PlayerManager::GetInstance();
}

} // namespace Singleton
