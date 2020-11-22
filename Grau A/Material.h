#pragma once
#include <string>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

using namespace std;

class Material
{
private:
	string id;
	glm::vec3* ka;
	glm::vec3* kd;
	glm::vec3* ks;
	float ns;
	string map_kd;
	string map_ks;
	unsigned int tid_mapkd;
	unsigned int tid_mapks;

public:
	void setId(string id);
	string getId();
	void setKa(glm::vec3* ka);
	glm::vec3* getKa();
	void setKd(glm::vec3* kd);
	glm::vec3* getKd();
	void setKs(glm::vec3* ks);
	glm::vec3* getKs();
	void setNs(float ns);
	float getNs();
	void setMap_Kd(string map_kd);
	string getMap_Kd();
	void setMap_Ks(string map_ks);
	string getMap_Ks();
	void setTid_Mapkd(unsigned int tid_mapkd);
	void setTid_Mapks(unsigned int tid_mapks);
};
