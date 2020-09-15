#include "Mesh.h"


void Mesh::addInfo(string mtllib, glm::vec3 min, glm::vec3 max, vector<glm::vec3*> vertex, 
	vector<glm::vec3*> norms, vector<glm::vec2*> texts, vector<Group*> groups ) {

	this->mtllib = mtllib;
	this->min = min;
	this->max = max;
	this->vertex = vertex;
	this->norms = norms;
	this->texts = texts;
	this->groups = groups;
}

vector<glm::vec3*> Mesh::getVertex()
{
	return vertex;
}

vector<glm::vec3*> Mesh::getNorms()
{
	return norms;
}

vector<glm::vec2*> Mesh::getTexts()
{
	return texts;
}

vector<Group*> Mesh::getGroups()
{
	return groups;
}
