#pragma once

#ifndef BUILDER_BUILDER_H
#define BUILDER_BUILDER_H

#include <iostream>

namespace Builder {

enum class HouseType {
	ONE_ROOM_HOUSE,
	ONE_ROOM_HOUSE_WITHOUT_WINDOWS_AND_DOORS,
	ONE_ROOM_SPACE_HOUSE,
};

class IAbout {
public:
	virtual void About() const = 0;
};

class OneRoomHouse : public IAbout {
public:
	virtual void About() const override;
};

class OneRoomSpaceHouse : public IAbout {
public:
	virtual void About() const override;
};

template <class T>
class IGet_Ptr {
public:
	virtual T* Get() = 0;
	virtual const T* Get() const = 0;
};

class HouseBuilder {
public:
	virtual void Reset() = 0;

	virtual void BuildWalls() {}
	virtual void BuildDoors() {}
	virtual void BuildWindows() {}
	virtual void BuildRoof() {}
};

class OneRoomHouseBuilder : public HouseBuilder, public IGet_Ptr<OneRoomHouse> {
private:
	OneRoomHouse m_oneRoomHouse {};

public:
	virtual void Reset() override;

	virtual void BuildWalls();
	virtual void BuildDoors();
	virtual void BuildWindows();
	virtual void BuildRoof();

	virtual OneRoomHouse* Get() override;
	virtual const OneRoomHouse* Get() const override;
};

class OneRoomSpaceHouseBuilder : public HouseBuilder, public IGet_Ptr<OneRoomSpaceHouse> {
private:
	OneRoomSpaceHouse m_oneRoomSpaceHouse {};

public:
	virtual void Reset() override;

	virtual void BuildWalls();
	virtual void BuildDoors();
	virtual void BuildWindows();

	virtual OneRoomSpaceHouse* Get() override;
	virtual const OneRoomSpaceHouse* Get() const override;
};


class HouseForeman {
private:
	HouseBuilder* m_houseBuilder;

private:
	void BuildOneRoomHouse();
	void BuildOneRoomHouseWithoutWindowsAndDoors();
	void BuildOneRoomSpaceHouse();

public:
	HouseForeman(HouseBuilder& houseBuilder);
	void ChangeBuilder(HouseBuilder& houseBuilder);
	void BuildHouse(const HouseType& houseType);
};


} // namespace Builder

#endif // !BUILDER_BUILDER_H
