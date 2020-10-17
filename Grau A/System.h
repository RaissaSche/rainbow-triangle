#ifndef SYSTEM_H
#define SYSTEM_H
#define GLEW_STATIC

// Internal
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <math.h>

// External Libs
#include <GL\glew.h>
#include <GLFW\glfw3.h>

// GLM Includes
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

// Headers
#include "Shader.h"
#include "Time.h"
#include "Obj3D.h"
#include "Material.h"

class System
{
private:
	// Screen
	int width, height;
	vector<Obj3D*> objs;
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUp;
	glm::vec3 lightPos;
	float la;

public:
	GLFWwindow* window;
	Shader coreShader;

public:
	System();
	~System();

	int GLFWInit();
	int OpenGLSetup();
	int SystemSetup();

	void Run();

	void Finish();

	Material* getMaterials(vector<Material*> materials, string material);
	void populateMtlValues(Material* material, int loc);
};

#endif