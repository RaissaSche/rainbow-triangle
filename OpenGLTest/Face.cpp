#include "Face.h"

Face::~Face() {}

Face::Face(vector<int> verts, int numVertices) {
	this->verts = verts;
	this->numVertices = numVertices;
}

Face::Face(vector<int> verts, vector<int> norms, int numVertices) {
	this->verts = verts;
	this->norms = norms;
	this->numVertices = numVertices;
}

Face::Face(vector<int> verts, vector<int> texts, int numVertices) {
	this->verts = verts;
	this->texts = texts;
	this->numVertices = numVertices;
}

Face::Face(vector<int> verts, vector<int> norms, vector<int> texts, int numVertices) {
	this->verts = verts;
	this->norms = norms;
	this->texts = texts;
	this->numVertices = numVertices;
}