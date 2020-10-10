#include "Material.h"

void Material::setId(string id)
{
	this->id = id;
}

void Material::setKa(glm::vec3* ka)
{
	this->ka = ka;
}

void Material::setKd(glm::vec3* kd)
{
	this->kd = kd;
}

void Material::setKs(glm::vec3* ks)
{
	this->ks = ks;
}

void Material::setNs(float ns)
{
	this->ns = ns;
}

void Material::setMap_Kd(string map_kd)
{
	this->map_kd = map_kd;
}

void Material::setTid(unsigned int tid)
{
	this->tid = tid;
}
