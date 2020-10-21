#pragma once
#include "Obj3D.h"
#include "Light.h"

class ConfigureScene
{
private:
	vector<Obj3D*> objs;
	vector<Light*> lights;
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUp;
	int width, height;
public:
	void readFile(string fileName);
	vector<Obj3D*> getObjs();
	vector<Light*> getLights();
	glm::vec3 getCameraPos();
	glm::vec3 getCameraTarget();
	glm::vec3 getCameraUp();
	int getWidth();
	int getHeight();
};
