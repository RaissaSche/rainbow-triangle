#include "Face.h"


void Face::addInfo(int vp, int vt, int vn)
{
	verts.push_back(vp);
	if (vt != -1) {
		texts.push_back(vt);
	}
	if (vn != -1) {
		norms.push_back(vn);
	}
}

int Face::getNumOfVertices()
{
	return numOfVertices;
}

void Face::setNumOfVertices(int numOfVertices)
{
	this->numOfVertices = numOfVertices;
}

std::vector<int> Face::getVerts()
{
	return verts;
}

std::vector<int> Face::getNorms()
{
	return norms;
}

std::vector<int> Face::getTexts()
{
	return texts;
}
