#include "Group.h"


unsigned int Group::getVAO()
{
	return VAO;
}

void Group::setVAO(unsigned int VAO)
{
	this->VAO = VAO;
}

int Group::getNumOfvertices()
{
	return faces.size() * 3;
}

void Group::addFace(Face* face)
{
	faces.push_back(face);
}

vector<Face*> Group::getFaces()
{
	return faces;
}

void Group::setName(string name)
{
	this->name = name;
}

void Group::setMaterial(string material)
{
	this->material = material;
}

string Group::getMaterial()
{
	return material;
}
