#pragma once
#include "Obj3D.h"

class ConfigureScene
{
private:
	vector<Obj3D*> objs;
	vector<float> animationPath;
	glm::mat3 lights;
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUp;
	int width, height, lightNum;
	float la, ld, ls;
public:
	void readFile(string fileName);
	void readAnimationFile(string fileName);
	vector<Obj3D*> getObjs();
	glm::mat3 getLights();
	glm::vec3 getCameraPos();
	glm::vec3 getCameraTarget();
	glm::vec3 getCameraUp();
	int getWidth();
	int getHeight();
	int getLightNum();
	void setLa(float la);
	float getLa();
	void setLd(float ld);
	float getLd();
	void setLs(float ls);
	float getLs();
};
