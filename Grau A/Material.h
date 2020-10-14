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
	unsigned int tid;

public:
	void setId(string id);
	string getId();
	void setKa(glm::vec3* ka);
	glm::vec3* getKa();
	void setKd(glm::vec3* kd);
	void setKs(glm::vec3* ks);
	void setNs(float ns);
	void setMap_Kd(string map_kd);
	void setTid(unsigned int tid);
};
