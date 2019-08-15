#include "run.h"

namespace TemplateMethod {

void Run() {

	std::shared_ptr<Mesh> mesh_01 { new Mesh {} };
	std::shared_ptr<Mesh> mesh_02 { new Mesh {} };
	mesh_01->AddCoords(
		{
			{ 1.0f, 0.0f, 1.0f },
			{ 2.0f, 0.3f, 10.0f },
			{ 1.0f, 0.6f, 5.0f },
		}
	);
	mesh_02->AddCoords(
		{
			{ 1.0f, 0.6f, 5.0f },
			{ 0.1f, 6.0f, 0.5f },
			{ 0.2f, 0.3f, 0.9f },
		}
	);

	std::shared_ptr<Object> object_01 { new Object {} };
	object_01->AddMesh("mesh_01", mesh_01);
	object_01->AddMesh("mesh_02", mesh_02);

	std::shared_ptr<Selection> selection { new SelectionObject {} };
	selection->AddSelectedObject("object_01", object_01);

	std::cout << "Centroid of selected objects: " << selection->GetCentroid() << std::endl;
}

} // namespace TemplateMethod
