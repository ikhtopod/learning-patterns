#pragma once

#ifndef FLYWEIGHT_FLYWEIGHT_H
#define FLYWEIGHT_FLYWEIGHT_H

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <map>

namespace Flyweight {

struct XYZ {
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	XYZ() = default;
	XYZ(float x, float y, float z);

	operator std::string() const;
};

struct Position : XYZ {};

struct Rotation : XYZ {};

struct Scale : XYZ {
	Scale();
};

struct Transform {
	Position position;
	Rotation rotation;
	Scale scale;

	operator std::string() const;
};


class Object {
private:
	const std::string m_name;

public:
	Object(const std::string& name);
	bool operator<(const Object& rhs) const;
	void Transformation(const Transform& transform) const;
	std::string GetName() const;
};

class ObjectFactory {
private:
	std::map<std::string, Object*> m_cache {};

public:
	virtual ~ObjectFactory();
	Object* Get(const std::string& name);
	size_t Size() const;
};

} // namespace Flyweight

#endif // !FLYWEIGHT_FLYWEIGHT_H
