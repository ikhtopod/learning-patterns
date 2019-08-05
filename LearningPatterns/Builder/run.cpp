#include "run.h"

namespace Builder {

void Run() {
	{
		OneRoomHouseBuilder oneRoomHouseBuilder {};

		HouseForeman houseForeman { oneRoomHouseBuilder };
		houseForeman.BuildHouse(HouseType::ONE_ROOM_HOUSE);

		OneRoomHouse* oneRoomHouse = oneRoomHouseBuilder.Get();
		oneRoomHouse->About();
	}

	std::cout << "=================" << std::endl;

	{
		OneRoomHouseBuilder oneRoomHouseBuilder {};
		HouseForeman houseForeman { oneRoomHouseBuilder };
		OneRoomHouse* oneRoomHouse = oneRoomHouseBuilder.Get();

		houseForeman.BuildHouse(HouseType::ONE_ROOM_HOUSE);
		oneRoomHouse->About();

		houseForeman.BuildHouse(HouseType::ONE_ROOM_HOUSE_WITHOUT_WINDOWS_AND_DOORS);
		oneRoomHouse->About();
	}

	std::cout << "=================" << std::endl;

	{
		OneRoomHouseBuilder oneRoomHouseBuilder {};
		HouseForeman houseForeman { oneRoomHouseBuilder };
		OneRoomHouse* oneRoomHouse = oneRoomHouseBuilder.Get();

		houseForeman.BuildHouse(HouseType::ONE_ROOM_HOUSE);
		oneRoomHouse->About();

		houseForeman.BuildHouse(HouseType::ONE_ROOM_HOUSE_WITHOUT_WINDOWS_AND_DOORS);
		oneRoomHouse->About();

		OneRoomSpaceHouseBuilder oneRoomSpaceHouseBuilder {};
		houseForeman.ChangeBuilder(oneRoomSpaceHouseBuilder);
		OneRoomSpaceHouse* oneRoomSpaceHouse = oneRoomSpaceHouseBuilder.Get();

		houseForeman.BuildHouse(HouseType::ONE_ROOM_SPACE_HOUSE);
		oneRoomSpaceHouse->About();
	}
}

} // namespace Builder
