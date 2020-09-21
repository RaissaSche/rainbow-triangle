#include "Obj3D.h"


void Obj3D::addInfo(Mesh* mesh, glm::mat4 transform, int status, bool disposable, glm::vec3 direction) {
	this->mesh = mesh;
	this->transform = transform;
	this->status = status;
	this->erasable = erasable;
	this->direction = direction;
}

void Obj3D::setStatus(int status)
{
	this->status = status;
}

int Obj3D::getStatus()
{
	return status;
}

void Obj3D::setErasable(bool erasable)
{
	this->erasable = erasable;
}

bool Obj3D::isErasable()
{
	return erasable;
}

void Obj3D::setDirection(glm::vec3 direction)
{
	this->direction = direction;
}

glm::vec3 Obj3D::getDirection()
{
	return direction;
}

Mesh* Obj3D::getMesh() {
	return mesh;
}

glm::mat4 Obj3D::getTransform()
{
	return transform;
}
