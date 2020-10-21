#include "Light.h"


void Light::setLightPos(glm::vec3* lightPos)
{
	this->lightPos = lightPos;
}

glm::vec3* Light::getLightPos()
{
	return lightPos;
}

void Light::setLa(float la)
{
	this->la = la;
}

float Light::getLa()
{
	return la;
}

void Light::setLd(float ld)
{
	this->ld = ld;
}

float Light::getLd()
{
	return ld;
}

void Light::setLs(float ls)
{
	this->ls = ls;
}

float Light::getLs()
{
	return ls;
}
