#include "Face.h"


Face::Face(std::vector<int> verts, int numVertices) {
	this->verts = verts;
	this->numVertices = numVertices;
}

Face::Face(std::vector<int> verts, std::vector<int> norms, int numVertices) {
	this->verts = verts;
	this->norms = norms;
	this->numVertices = numVertices;
}

Face::Face(std::vector<int> verts, std::vector<int> texts, int numVertices) {
	this->verts = verts;
	this->texts = texts;
	this->numVertices = numVertices;
}

Face::Face(std::vector<int> verts, std::vector<int> norms, std::vector<int> texts, int numVertices) {
	this->verts = verts;
	this->norms = norms;
	this->texts = texts;
	this->numVertices = numVertices;
}