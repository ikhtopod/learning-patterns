#include "templatemethod.h"

namespace TemplateMethod {

Vector3::Vector3() : Vector3(0, 0, 0) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& vec3) :
	Vector3(vec3.x, vec3.y, vec3.z) {}

void Vector3::operator=(const Vector3& rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

bool Vector3::operator<(const Vector3& rhs) const {
	return x < rhs.x && y < rhs.y && z < rhs.z;
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}

Vector3 Vector3::operator+=(const Vector3& rhs) const {
	return *this + rhs;
}

Vector3 Vector3::operator/(float rhs) const {
	if (rhs) {
		return { x / rhs, y / rhs, z / rhs };
	} else {
		return {};
	}
}

Vector3 Vector3::operator/=(float rhs) const {
	return *this / rhs;
}

std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs) {
	return lhs << '(' << rhs.x << ';' << rhs.y << ';' << rhs.z << ')';
}


void Mesh::AddCoords(const std::vector<Vector3>& coords) {
	m_coords.insert(m_coords.end(), coords.begin(), coords.end());
}

const std::vector<Vector3>& Mesh::GetCoords() const {
	return m_coords;
}

void Object::AddMesh(const std::string& name, const std::shared_ptr<Mesh>& mesh) {
	m_mesh[name] = mesh;
}

const std::map<std::string, std::shared_ptr<Mesh>>& Object::GetMeshes() const {
	return m_mesh;
}

void Selection::
AddSelectedObject(const std::string& name, const std::shared_ptr<Object>& object) {
	m_selectedObjects[name] = object;
}

bool Selection::HasSelectedObjects() const {
	return !m_selectedObjects.empty();
}

Vector3 Selection::GetCentroid() const {
	Vector3 centroid {};
	if (!HasSelectedObjects()) return centroid;

	std::vector<Vector3> tmpCentroidVec = DoGetVerticesForCentroid();
	std::set<Vector3> centroidVertices { tmpCentroidVec.begin(), tmpCentroidVec.end() };
	tmpCentroidVec.erase(tmpCentroidVec.begin(), tmpCentroidVec.end());
	tmpCentroidVec.clear();

	if (centroidVertices.size() > 1) {
		centroid = std::accumulate(std::next(centroidVertices.begin()), centroidVertices.end(),
			*centroidVertices.begin(), std::plus<Vector3>());
		centroid /= static_cast<float>(centroidVertices.size());
	} else {
		centroid = *centroidVertices.begin();
	}

	centroidVertices.clear();

	return centroid;
}


std::vector<Vector3> SelectionObject::DoGetVerticesForCentroid() const {
	std::vector<Vector3> objectVertices {};

	for (const auto& [objectName, objectPtr] : m_selectedObjects) {
		for (const auto& [meshName, meshPtr] : objectPtr->GetMeshes()) {
			for (const auto& vec3 : meshPtr->GetCoords()) {
				objectVertices.push_back(vec3);
			}
		}
	}

	return objectVertices;
}


} // namespace TemplateMethod
