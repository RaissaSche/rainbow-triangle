#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

class Face
	//get number of vectors from array size
{
private:
	std::vector<int> verts, norms, texts;
	int numOfVertices = 0;

public:
	//when empty, pass -1 value - maybe will need/be better to receive pointers
	void addInfo(int vp, int vt, int vn);
	void setNumOfVertices(int numOfVertices);
	int getNumOfVertices();
	std::vector<int> getVerts();
	std::vector<int> getNorms();
	std::vector<int> getTexts();
};