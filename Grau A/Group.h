#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>
#include <vector>

#include "Face.h"
#include "Material.h"

using namespace std;

class Group
{
private:
	string name;
	string mtlName;
	vector<Material*> materials;
	vector<Face*> faces;
	unsigned int VAO;

public:
	void setVAO(unsigned int VAO);
	unsigned int getVAO();
	int getNumOfvertices();
	void addFace(Face* face);
	vector<Face*> getFaces();
	void setName(string name);
	void setMtlName(string mtlName);
	void addMaterial(Material* material);
};
