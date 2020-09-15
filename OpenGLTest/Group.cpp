#include "Group.h"


Group::Group(string name, string material, vector<Face*> faces) {
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
	return faces.size()* vertexesPerFace;
}

vector<Face*> Group::getFaces()
{
	return faces;
}
