#include "Group.h"


void Group::initializeGroup(string name, string material, vector<Face*> faces) {
	this->name = name;
	this->material = material;
	this->faces = faces;
}

unsigned int Group::getVAO()
{
	return VAO;
}

void Group::setVAO(unsigned int VAO)
{
	this->VAO = VAO;
}

int Group::getNumOfvertices(int vertexesPerFace)
{
	return faces.size() * vertexesPerFace;
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
