#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <string>
#include <vector>

#include "Face.h"

using namespace std;

class Group
{
public:
	string name;
	string material;
	vector<Face*> faces;
	unsigned int VAO;

	Group(string name, string material, vector<Face*> faces);
};
