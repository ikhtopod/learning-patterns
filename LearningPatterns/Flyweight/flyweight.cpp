#include "flyweight.h"

namespace Flyweight {

XYZ::XYZ(float x, float y, float z) : x(x), y(y), z(z) {}

Scale::Scale() : XYZ(1.0f, 1.0f, 1.0f) {}


Object::Object(const std::string& name) : m_name(name) {}

bool Object::operator<(const Object& rhs) const {
	return m_name < rhs.m_name;
}

void Object::Transformation(const Transform& transform) const {
	std::cout << "Object name: " << m_name << std::endl << 
		std::string(transform) << std::endl;
}

std::string Object::GetName() const {
	return m_name;
}

XYZ::operator std::string() const {
	std::ostringstream ostr {};
	ostr << '(' << x << "; " << y << "; " << z << ')';

	return ostr.str();
}

Transform::operator std::string() const {
	std::ostringstream ostr {};
	ostr << "Position: " << std::string(position) << std::endl <<
		"Rotation: " << std::string(rotation) << std::endl <<
		"Scale: " << std::string(scale) << std::endl;

	return ostr.str();
}

ObjectFactory::~ObjectFactory() {
	for (auto& [key, object] : m_cache) {
		std::cout << "Object \"" << object->GetName();
		delete m_cache[key];
		m_cache[key] = nullptr;
		std::cout << "\" deleted from ObjectFactory" << std::endl;
	}

	m_cache.clear();
}

Object* ObjectFactory::Get(const std::string& name) {
	if (m_cache.count(name) == 0) {
		m_cache[name] = new Object { name };
	}

	return m_cache.at(name);
}

size_t ObjectFactory::Size() const {
	return m_cache.size();
}

} // namespace Flyweight
