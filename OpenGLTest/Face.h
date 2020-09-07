#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

class Face
{
public:
	int numVertices;
	vector<int> verts, norms, texts;

	Face(vector<int> verts, int numVertices);
	Face(vector<int> verts, vector<int> norms, int numVertices);
	Face(vector<int> verts, vector<int> texts, int numVertices);
	Face(vector<int> verts, vector<int> norms, vector<int> texts, int numVertices);
};