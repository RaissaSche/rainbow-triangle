#include "Obj3D.h"


Obj3D::Obj3D(Mesh* mesh, glm::mat4 transform, int status, bool disposable, glm::vec3 direction) {
	this->mesh = mesh;
	this->transform = transform;
	this->status = status;
	this->disposable = disposable;
	this->direction = direction;
}

Mesh* Obj3D::GetMesh() {
	return mesh;
}
