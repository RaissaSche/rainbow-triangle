#include "ManageObj.h"
#include "Group.h"
#include <fstream>
#include <sstream>
#include <iostream>


Obj3D* ManageObj::readObj(string fileName)
{
	Mesh* mesh = new Mesh();
	Group* g_atual = new Group();
	ifstream arq(fileName);
	bool firstGroup = true;

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;
		sline >> temp;

		//cout << line << '\n';

		if (temp == "v") {
			float x, y, z;
			sline >> x >> y >> z;
			//cout << x << ' ' << y << ' ' << z << ' ' << '\n';
			glm::vec3* vert = new glm::vec3(x, y, z);
			mesh->addVert(vert);
		}
		else if (temp == "vt") {
			float x, y;
			sline >> x >> y;
			//cout << x << ' ' << y << '\n';
			glm::vec2* text = new glm::vec2(x, y);
			mesh->addText(text);
		}
		else if (temp == "vn") {
			float x, y, z;
			sline >> x >> y >> z;
			//cout << x << ' ' << y << ' ' << z << ' ' << '\n';
			glm::vec3* norm = new glm::vec3(x, y, z);
			mesh->addNorm(norm);
		}
		else if (temp == "f") {
			cout << line << '\n';
			Face* f = new Face();
			string token;
			while (sline >> token) { //v/t/n, por exemplo
				cout << token << '\n';

				stringstream stoken;
				string aux;
				stoken << token;

				int it = 0;
				int v = -1;
				int t = -1;
				int n = -1;

				while (getline(stoken, aux, '/')) {
					cout << aux << '\n';
					// v, v/t/n, v/t e v//n
					switch (it) {
					case 0: v = stoi(aux) - 1;
						break;
					case 1:
						if (!aux.empty()) { 
							t = stoi(aux) -1;
						}
						break;
					case 2: 
						n = stoi(aux) -1;
						break;
					}
					it++;
				}
				cout << v << '+' << t << '+' << n << '\n';
				f->addInfo(v, t, n);
			}
			g_atual->addFace(f);
		}
		else if (temp == "g") {
			string token;
			sline >> token;
			if (firstGroup){
				//pode ter nada e l� no meio decretar o segundo grupo?
				g_atual->setName(token);
				firstGroup = false;
			}
			else {
				mesh->addGroup(g_atual);
				g_atual = new Group;
				g_atual->setName(token);
			}
		}
		else if (temp == "mtllib") {
			string token;
			sline >> token;

			g_atual->setMaterial(token);
		}

		/*else { //else-if
			//verificar outras possibilidades:
			//g, vn, ...
		}*/	
	}
	mesh->addGroup(g_atual);
	Obj3D* obj3D = new Obj3D();
	obj3D->addInfo(mesh, glm::mat4(1.0), 1, false, glm::vec3(0.0f, 0.0f, 0.0f));
	return obj3D;
}


void ManageObj::ObjToVBO(Obj3D* obj3D) {

	Mesh* mesh = obj3D->getMesh();

	for (int i = 0; i < mesh->getGroups().size(); i++)
	{
		Group* g = mesh->getGroups()[i];
		vector<float> vs;
		vector<float> vts;
		vector<float> vns;

		for (Face* f : g->getFaces()) {
			for (int i = 0; i < 3; i++) { //get the "3" from face's number of vertices
				//vertex
				glm::vec3* v = mesh->getVertex()[f->getVerts()[i]];
				vs.push_back(v->x);
				vs.push_back(v->y);
				vs.push_back(v->z);

				f->setNumOfVertices(f->getNumOfVertices() + 1);

				//norms
				if (!f->getNorms().empty()) {
					glm::vec3* vn = mesh->getNorms()[f->getNorms()[i]];
					vns.push_back(vn->x);
					vns.push_back(vn->y);
					vns.push_back(vn->z);
				}
				//texts
				if (!f->getTexts().empty()) {
					glm::vec2* vt = mesh->getTexts()[f->getTexts()[i]];
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

		g->setVAO(VAO);
	}
}
