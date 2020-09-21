#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>
#include <vector>

#include "Face.h"

using namespace std;

class Group
{
private:
	string name;
	string material;
	vector<Face*> faces;
	unsigned int VAO;

public:
	void initializeGroup(string name, string material, vector<Face*> faces);
	void setVAO(unsigned int VAO);
	unsigned int getVAO();
	int getNumOfvertices(int vertexesPerFace);
	void addFace(Face* face);
	vector<Face*> getFaces();
	void setName(string name);
	void setMaterial(string material);
};
