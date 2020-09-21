#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Mesh.h"

class Obj3D
{
private:
	Mesh* mesh;
	glm::mat4 transform;
	int status;
	bool erasable;
	glm::vec3 direction;

public:

	void addInfo(Mesh* mesh, glm::mat4 transform, int status, bool erasable, glm::vec3 direction);
	void setStatus(int status);
	int getStatus();
	void setErasable(bool erasable);
	bool isErasable();
	void setDirection(glm::vec3 direction);
	glm::vec3 getDirection();
	Mesh* getMesh();
	glm::mat4 getTransform();
};
