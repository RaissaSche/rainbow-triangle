#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Obj3D.h"

class ManageObj
{
public:
	Obj3D* readObj(string fileName);
	void ObjToVBO(Obj3D* obj3D);
};
