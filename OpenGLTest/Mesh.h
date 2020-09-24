#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>

#include "Group.h"

using namespace std;

class Mesh
{
private:
	string mtllib;
	glm::vec3* min;
	glm::vec3* max;

	vector<glm::vec3*> vertex;
	vector<glm::vec3*> norms;
	vector<glm::vec2*> texts;
	vector<Group*> groups;

public:
	void addInfo(string mtllib, glm::vec3* min, glm::vec3* max, vector<glm::vec3*> vertex,
		vector<glm::vec3*> norms, vector<glm::vec2*> texts, vector<Group*> groups);
	void addVert(glm::vec3* vert);
	vector<glm::vec3*> getVertex();
	void addNorm(glm::vec3* norm);
	vector<glm::vec3*> getNorms();
	void addText(glm::vec2* text);
	vector<glm::vec2*> getTexts();
	void addGroup(Group* group);
	vector<Group*> getGroups();
	void setMin(glm::vec3* min);
	void setMax(glm::vec3* max);
};