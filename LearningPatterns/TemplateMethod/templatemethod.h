#pragma once

#ifndef TEMPLATEMETHOD_TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_TEMPLATEMETHOD_H

#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>

namespace TemplateMethod {

struct Vector3 final {
	float x, y, z;

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& vec3);
	void operator=(const Vector3& rhs);
	~Vector3() = default;

	bool operator<(const Vector3& rhs) const;
	Vector3 operator+(const Vector3& rhs) const;
	Vector3 operator+=(const Vector3& rhs) const;
	Vector3 operator/(float rhs) const;
	Vector3 operator/=(float rhs) const;

	friend std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs);
};

class Mesh {
private:
	std::vector<Vector3> m_coords {};

public:
	void AddCoords(const std::vector<Vector3>& coords);
	const std::vector<Vector3>& GetCoords() const;
};

class Object {
private:
	std::map<std::string, std::shared_ptr<Mesh>> m_mesh {};

public:
	void AddMesh(const std::string& name, const std::shared_ptr<Mesh>& mesh);
	const std::map<std::string, std::shared_ptr<Mesh>>& GetMeshes() const;
};

class Selection {
protected:
	using MapObjectPtr = std::map<std::string, std::shared_ptr<Object>>;

protected:
	MapObjectPtr m_selectedObjects {};

protected:
	virtual std::vector<Vector3> DoGetVerticesForCentroid() const = 0; // Template Method

public:
	void AddSelectedObject(const std::string& name, const std::shared_ptr<Object>& object);
	bool HasSelectedObjects() const;
	Vector3 GetCentroid() const;
};

class SelectionObject : public Selection {
protected:
	virtual std::vector<Vector3> DoGetVerticesForCentroid() const override;
};

} // namespace TemplateMethod

#endif // !TEMPLATEMETHOD_TEMPLATEMETHOD_H
