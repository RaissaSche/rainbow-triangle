#include "Obj3D.h"


void Obj3D::addInfo(Mesh* mesh, glm::mat4 transform, int status, bool disposable, glm::vec3 direction) {
	this->mesh = mesh;
	this->transform = transform;
	this->status = status;
	this->disposable = disposable;
	this->direction = direction;
}

Mesh* Obj3D::GetMesh() {
	return mesh;
}

glm::mat4 Obj3D::getTransform()
{
	return transform;
}
