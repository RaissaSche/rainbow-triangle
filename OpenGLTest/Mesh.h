#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>

#include "Group.h"

using namespace std;

class Mesh
{
	string mtllib;
	glm::vec3 min, max;

	vector<glm::vec3*> vertex;
	vector<glm::vec3*> norms;
	vector<glm::vec2*> texts;
	vector<Group*> groups;

public:
	void addInfo(string mtllib, glm::vec3 min, glm::vec3 max, vector<glm::vec3*> vertex,
		vector<glm::vec3*> norms, vector<glm::vec2*> texts, vector<Group*> groups);
	vector<glm::vec3*> getVertex();
	vector<glm::vec3*> getNorms();
	vector<glm::vec2*> getTexts();
	vector<Group*> getGroups();
	
};