#include "ManageObj.h"


void ManageObj::ObjToVBO(Obj3D* obj3D) {
	
	Mesh* mesh = obj3D->GetMesh();
	
	for (Group* g : mesh->groups) {
		vector<float> vs;
		vector<float> vts;
		vector<float> vns;

		glGenVertexArrays(1, &g->VAO);
		glGenBuffers(1, &g->VBO);

		glBindVertexArray(g->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, g->VBO);

		for (Face* f : g->faces) {
			for (int i = 0; i < f->numVertices; i++) {
				//vertex
				glm::vec3* v = mesh->vertex[f->verts[i]];
				vs.push_back(v->x);
				vs.push_back(v->y);
				vs.push_back(v->z);

				glBufferData(GL_ARRAY_BUFFER, i * sizeof(GLfloat), vs.data(), GL_STATIC_DRAW);
				// vertex positions
				/*glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, i * sizeof(GLfloat), (void*)0);*/

				//texts
				glm::vec2* vt = mesh->texts[f->texts[i]];
				vts.push_back(v->x);
				vts.push_back(v->y);

				// vertex texture coords
				/*glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, i * sizeof(GLfloat), (void*)0);*/

				//norms
				glm::vec3* vn = mesh->norms[f->norms[i]];
				vns.push_back(vn->x);
				vns.push_back(vn->y);
				vns.push_back(vn->z);

				// vertex normals
				/*glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, i * sizeof(GLfloat), (void*)0);*/

				glBindVertexArray(0);
			}
		}
	}

}
