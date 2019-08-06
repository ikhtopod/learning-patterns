#include "run.h"

#include <vector>

namespace ChainOfResponsibility {

void Run() {
	OneHandedAxe oneHandedAxe {};
	
	Axe axe {};
	axe.SetHandler(oneHandedAxe);
	
	Weapon weapon {};
	weapon.SetHandler(axe);
	
	CraftSystem craftSystem {};
	craftSystem.SetHandler(weapon);


	CraftInfo craftInfo { craftSystem };
	craftInfo.ShowInfo(CraftType::Weapon);
	craftInfo.ShowInfo(CraftType::OneHandedAxe);
	craftInfo.ShowInfo(CraftType::Weapon);
	craftInfo.ShowInfo(CraftType::None);
	craftInfo.ShowInfo(CraftType::Weapon);
	craftInfo.ShowInfo(CraftType::Axe);
}

} // namespace ChainOfResponsibility
