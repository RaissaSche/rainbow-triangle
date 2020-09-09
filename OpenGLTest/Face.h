#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

class Face
{
public:
	int numVertices;
	std::vector<int> verts, norms, texts;

	Face(std::vector<int> verts, int numVertices);
	Face(std::vector<int> verts, std::vector<int> norms, int numVertices);
	Face(std::vector<int> verts, std::vector<int> texts, int numVertices);
	Face(std::vector<int> verts, std::vector<int> norms, std::vector<int> texts, int numVertices);
};