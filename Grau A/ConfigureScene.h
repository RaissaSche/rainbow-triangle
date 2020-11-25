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
	glm::vec3 fog;
	int width, height, lightNum, idFog;
	float la, ld, ls;
	string animFile;
public:
	ConfigureScene();
	void readFile(string fileName);
	vector<float> readAnimationFile();
	vector<Obj3D*> getObjs();
	glm::mat3 getLights();
	glm::vec3 getCameraPos();
	glm::vec3 getCameraTarget();
	glm::vec3 getCameraUp();
	glm::vec3 getFog();
	int getWidth();
	int getHeight();
	int getLightNum();
	int getIdFog();
	void setLa(float la);
	float getLa();
	void setLd(float ld);
	float getLd();
	void setLs(float ls);
	float getLs();
};
