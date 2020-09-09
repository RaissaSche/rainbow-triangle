#include "Group.h"


Group::Group(string name, string material, vector<Face*> faces) {
	this->name = name;
	this->material = material;
	this->faces = faces;
}