#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>
#include <vector>

#include "Face.h"

using namespace std;

class Group
{
	string name;
	string material;
	vector<Face*> faces;
	unsigned int VAO;

public:
	Group(string name, string material, vector<Face*> faces);
	unsigned int getVAO();
	void setVAO(unsigned int VAO);
	int getNumOfvertices(int vertexesPerFace);
	vector<Face*> getFaces();
};
