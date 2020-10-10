#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
#include "Obj3D.h"

class ManageObj
{
public:
	Obj3D* readObj(string fileName);
	vector<Material*> readMtl(string fileName);
	void ObjToVBO(Obj3D* obj3D);
};
