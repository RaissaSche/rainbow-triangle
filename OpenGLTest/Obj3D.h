#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Mesh.h"

class Obj3D
{
	Mesh* mesh;
	glm::mat4 transform;
	int status;
	bool disposable;
	glm::vec3 direction;

public:

	void addInfo(Mesh* mesh, glm::mat4 transform, int status, bool disposable, glm::vec3 direction);
	Mesh* GetMesh();
	glm::mat4 getTransform();
};
