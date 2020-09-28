#include "Obj3D.h"


void Obj3D::addInfo(Mesh* mesh, glm::mat4 transform, int status, bool erasable,
					glm::vec3 direction, string name, int id) {
	this->mesh = mesh;
	this->transform = transform;
	this->status = status;
	this->erasable = erasable;
	this->direction = direction;
	this->name = name;
	this->id = id;
}

void Obj3D::addInfoTranslate(float tx, float ty, float tz)
{
	transform = glm::mat4(1.0f);
	transform = glm::translate(transform, glm::vec3(tx, ty, tz));
}

void Obj3D::addInfoTransform(float tx, float ty, float tz, float s, float r)
{
	transform = glm::mat4(1.0f);
	transform = glm::rotate(transform, glm::radians(r), glm::vec3(tx, ty, tz));
	transform = glm::scale(transform, glm::vec3(s, s, s));
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

string Obj3D::getName()
{
	return name;
}

void Obj3D::setName(string name)
{
	this->name = name;
}

void Obj3D::setId(int id)
{
	this->id = id;
}
