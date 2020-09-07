#include "ManageObj.h"

ManageObj::~ManageObj() {}

void ManageObj::ObjToVBO(Obj3D* obj3D) {
	
	Mesh* mesh = obj3D->GetMesh();
	
	for (Group* g : mesh->groups) {
		vector<float> vs;
		vector<float> vts;
		vector<float> vns;
		for (Face* f : g->faces) {
			for (int i = 0; i < f->numVertices; i++) {
				glm::vec3 v = mesh->vertex[f->verts[i]];
				vs.push_back(v.x);
				vs.push_back(v.y);
				vs.push_back(v.z);

				glm::vec2 vt = mesh->texts[f->texts[i]];
				vts.push_back(vt.x);
				vts.push_back(vt.y);

				glm::vec3 vn = mesh->norms[f->norms[i]];
				vns.push_back(vn.x);
				vns.push_back(vn.y);
				vns.push_back(vn.z);
			}
		}
	}
}