#include "ManageObj.h"


void ManageObj::ObjToVBO(Obj3D* obj3D) {

	Mesh* mesh = obj3D->GetMesh();

	for (int i = 0; i < mesh->groups.size(); i++)
	{
		Group* g = mesh->groups[i];
		vector<float> vs;
		vector<float> vts;
		vector<float> vns;

		for (Face* f : g->faces) {
			for (int i = 0; i < 3; i++) { //get the "3" from face's number of vertices
				//vertex
				glm::vec3* v = mesh->vertex[f->getVerts()[i]];
				vs.push_back(v->x);
				vs.push_back(v->y);
				vs.push_back(v->z);
				//norms
				if (!f->getNorms().empty()) {
					glm::vec3* vn = mesh->norms[f->getNorms()[i]];
					vns.push_back(vn->x);
					vns.push_back(vn->y);
					vns.push_back(vn->z);
				}
				//texts
				if (!f->getTexts().empty()) {
					glm::vec2* vt = mesh->texts[f->getTexts()[i]];
					vts.push_back(v->x);
					vts.push_back(v->y);
				}
			}
		}

		GLuint VAO, VBOvs, VBOvns, VBOvts;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBOvs);
		glGenBuffers(1, &VBOvns);
		glGenBuffers(1, &VBOvts);

		glBindVertexArray(VAO);

		//VBOvs
		glBindBuffer(GL_ARRAY_BUFFER, VBOvs);
		glBufferData(GL_ARRAY_BUFFER, vs.size() * sizeof(GLfloat), vs.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		//VBOvns
		glBindBuffer(GL_ARRAY_BUFFER, VBOvns);
		glBufferData(GL_ARRAY_BUFFER, vns.size() * sizeof(GLfloat), vns.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		//VBOvts
		glBindBuffer(GL_ARRAY_BUFFER, VBOvts);
		glBufferData(GL_ARRAY_BUFFER, vts.size() * sizeof(GLfloat), vts.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);

		g->VAO = VAO;
	}
}
