#include "Material.h"


Material::Material()
{
	tid_mapkd = 0;
	tid_mapks = 0;
}

void Material::setId(string id)
{
	this->id = id;
}

string Material::getId()
{
	return id;
}

void Material::setKa(glm::vec3* ka)
{
	this->ka = ka;
}

glm::vec3* Material::getKa()
{
	return ka;
}

void Material::setKd(glm::vec3* kd)
{
	this->kd = kd;
}
glm::vec3* Material::getKd()
{
	return kd;
}

void Material::setKs(glm::vec3* ks)
{
	this->ks = ks;
}

glm::vec3* Material::getKs()
{
	return ks;
}

void Material::setNs(float ns)
{
	this->ns = ns;
}

float Material::getNs()
{
	return ns;
}
void Material::setMap_Kd(string map_kd)
{
	this->map_kd = map_kd;
}

string Material::getMap_Kd()
{
	return map_kd;
}

void Material::setMap_Ks(string map_ks)
{
	this->map_ks = map_ks;
}

string Material::getMap_Ks()
{
	return map_ks;
}

void Material::setTid_Mapkd(unsigned int tid_mapkd)
{
	this->tid_mapkd = tid_mapkd;
}

void Material::setTid_Mapks(unsigned int tid_mapks)
{
	this->tid_mapks = tid_mapks;
}

unsigned int Material::getTid_Mapks()
{
	return tid_mapks;
}
