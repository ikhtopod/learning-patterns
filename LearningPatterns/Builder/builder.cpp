#include "builder.h"

namespace Builder {


void OneRoomHouse::About() const {
	std::cout << "I'm One-Room House" << std::endl;
}

void OneRoomSpaceHouse::About() const {
	std::cout << "I'm One-Room Space House" << std::endl;
}

void HouseForeman::BuildOneRoomHouse() {
	m_houseBuilder->Reset();
	m_houseBuilder->BuildWalls();
	m_houseBuilder->BuildWindows();
	m_houseBuilder->BuildDoors();
	m_houseBuilder->BuildRoof();
}

void HouseForeman::BuildOneRoomHouseWithoutWindowsAndDoors() {
	m_houseBuilder->Reset();
	m_houseBuilder->BuildWalls();
	m_houseBuilder->BuildRoof();
}

void HouseForeman::BuildOneRoomSpaceHouse() {
	m_houseBuilder->Reset();
	m_houseBuilder->BuildWalls();
	m_houseBuilder->BuildWindows();
	m_houseBuilder->BuildDoors();
}

HouseForeman::HouseForeman(HouseBuilder& houseBuilder) :
	m_houseBuilder(&houseBuilder) {}

void HouseForeman::ChangeBuilder(HouseBuilder& houseBuilder) {
	m_houseBuilder = &houseBuilder;
}

void HouseForeman::BuildHouse(const HouseType& houseType) {
	switch (houseType) {
		case HouseType::ONE_ROOM_HOUSE:
			BuildOneRoomHouse();
			break;
		case HouseType::ONE_ROOM_HOUSE_WITHOUT_WINDOWS_AND_DOORS:
			BuildOneRoomHouseWithoutWindowsAndDoors();
			break;
		case HouseType::ONE_ROOM_SPACE_HOUSE:
			BuildOneRoomSpaceHouse();
			break;
		default:
			break;
	}
}


void OneRoomHouseBuilder::Reset() {
	std::cout << "One-room house was demolished." << std::endl;
}

OneRoomHouse* OneRoomHouseBuilder::Get() {
	return &m_oneRoomHouse;
}

const OneRoomHouse* OneRoomHouseBuilder::Get() const {
	return &m_oneRoomHouse;
}

void OneRoomSpaceHouseBuilder::Reset() {
	std::cout << "One-room space house was demolished." << std::endl;
}

OneRoomSpaceHouse* OneRoomSpaceHouseBuilder::Get() {
	return &m_oneRoomSpaceHouse;
}

const OneRoomSpaceHouse* OneRoomSpaceHouseBuilder::Get() const {
	return &m_oneRoomSpaceHouse;
}


void OneRoomHouseBuilder::BuildWalls() {
	std::cout << "Walls built for one-room house." << std::endl;
}

void OneRoomHouseBuilder::BuildDoors() {
	std::cout << "Doors built for one-room house." << std::endl;
}

void OneRoomHouseBuilder::BuildWindows() {
	std::cout << "Windows built for one-room house." << std::endl;
}

void OneRoomHouseBuilder::BuildRoof() {
	std::cout << "Roof built for one-room house." << std::endl;
}


void OneRoomSpaceHouseBuilder::BuildWalls() {
	std::cout << "Walls built for one-room space house." << std::endl;
}

void OneRoomSpaceHouseBuilder::BuildDoors() {
	std::cout << "Doors built for one-room space house." << std::endl;
}

void OneRoomSpaceHouseBuilder::BuildWindows() {
	std::cout << "Windows built for one-room space house." << std::endl;
}

} // namespace Builder
