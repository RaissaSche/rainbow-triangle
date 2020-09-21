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

void Mesh::addVert(glm::vec3* vert)
{
	this->vertex.push_back(vert);
}

vector<glm::vec3*> Mesh::getVertex()
{
	return vertex;
}

void Mesh::addNorm(glm::vec3* norm)
{
	this->norms.push_back(norm);
}

vector<glm::vec3*> Mesh::getNorms()
{
	return norms;
}

void Mesh::addText(glm::vec2* text)
{
	this->texts.push_back(text);
}

vector<glm::vec2*> Mesh::getTexts()
{
	return texts;
}

void Mesh::addGroup(Group* group)
{
	this->groups.push_back(group);
}

vector<Group*> Mesh::getGroups()
{
	return groups;
}
