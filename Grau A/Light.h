#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

class Light
{
private:
	glm::vec3* lightPos;
	float la, ld, ls;

public:
	void setLightPos(glm::vec3* lightPos);
	glm::vec3* getLightPos();
	void setLa(float la);
	float getLa();
	void setLd(float ld);
	float getLd();
	void setLs(float ls);
	float getLs();
};
