#include "ManageObj.h"
#include "Group.h"
#include "Material.h"
#include <fstream>
#include <sstream>


Obj3D* ManageObj::readObj(string fileName)
{
	Mesh* mesh = new Mesh();
	Group* g_atual = new Group();
	ifstream arq(fileName);
	bool firstGroup = true;
	glm::vec3* min = new glm::vec3(10000000.0f, 10000000.0f, 10000000.0f);
	glm::vec3* max = new glm::vec3(-10000000.0f, -10000000.0f, -10000000.0f);

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;
		sline >> temp;

		if (temp == "v") {
			float x, y, z;
			sline >> x >> y >> z;
			glm::vec3* vert = new glm::vec3(x, y, z);
			mesh->addVert(vert);
		}
		else if (temp == "vt") {
			float x, y;
			sline >> x >> y;
			glm::vec2* text = new glm::vec2(x, y);
			mesh->addText(text);
		}
		else if (temp == "vn") {
			float x, y, z;
			sline >> x >> y >> z;
			glm::vec3* norm = new glm::vec3(x, y, z);
			mesh->addNorm(norm);
		}
		else if (temp == "f") {
			Face* f = new Face();
			string token;
			while (sline >> token) {
				stringstream stoken;
				string aux;
				stoken << token;

				int it = 0;
				int v = -1;
				int t = -1;
				int n = -1;
				int x, y, z;

				while (getline(stoken, aux, '/')) {
					// v, v/t/n, v/t e v//n
					switch (it) {
					case 0:
						x = stoi(aux);
						v = x - 1;
						if (x > max->x) {
							max->x = x;
						}
						else if (x < min->x) {
							min->x = x;
						}
						break;
					case 1:
						y = stoi(aux);
						if (!aux.empty()) {
							t = y - 1;
							if (y > max->y) {
								max->y = y;
							}
							else if (y < min->y) {
								min->y = y;
							}
						}
						break;
					case 2:
						z = stoi(aux);
						n = z - 1;
						if (z > max->z) {
							max->z = z;
						}
						else if (z < min->z) {
							min->z = z;
						}
						break;
					}
					it++;
				}
				f->addInfo(v, t, n);
			}
			g_atual->addFace(f);
		}
		else if (temp == "g") {
			string token;
			sline >> token;
			if (firstGroup) {
				g_atual->setName(token);
				firstGroup = false;
			}
			else {
				mesh->addGroup(g_atual);
				g_atual = new Group();
				g_atual->setName(token);
			}
		}
		else if (temp == "usemtl") {
			string token;
			sline >> token;
			sline >> token;

			g_atual->setMaterial(token);
		}
	}
	mesh->addGroup(g_atual);
	mesh->setMax(max);
	mesh->setMin(min);
	Obj3D* obj3D = new Obj3D();
	obj3D->addInfo(mesh, glm::mat4(1.0), 1, false, glm::vec3(0.0f, 0.0f, 0.0f), fileName, 0);
	return obj3D;
}

vector<Material*> ManageObj::readMtl(string fileName)
{
	vector<Material*> materials;
	Material* material = new Material();
	bool firstMaterial = true;
	ifstream arq(fileName);

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;
		sline >> temp;

		if (temp == "newmtl") {
			string id;
			sline >> id;
			
			if (firstMaterial) {
				material->setId(id);
				firstMaterial = false;
			}
			else {
				materials.push_back(material);
				material = new Material();
				material->setId(id);
			}
		}
		else if (temp == "Ka") {
			float r, g, b;
			sline >> r >> g >> b;
			glm::vec3* ka = new glm::vec3(r, g, b);
			material->setKa(ka);
		}
		else if (temp == "Kd") {
			float r, g, b;
			sline >> r >> g >> b;
			glm::vec3* kd = new glm::vec3(r, g, b);
			material->setKd(kd);
		}
		else if (temp == "Ks") {
			float r, g, b;
			sline >> r >> g >> b;
			glm::vec3* ks = new glm::vec3(r, g, b);
			material->setKs(ks);
		}
		else if (temp == "Ns") {
			float ns;
			sline >> ns;
			material->setNs(ns);
		}
		else if (temp == "map_Kd") {
			string map_kd;
			sline >> map_kd;
			material->setMap_Kd(map_kd);
			material->setTid_Mapkd(1);
		}
		else if (temp == "map_Ks") {
			string map_kd;
			sline >> map_kd;
			material->setMap_Ks(map_kd);
			material->setTid_Mapks(2);
		}
	}
	materials.push_back(material);
	return materials;
}


void ManageObj::ObjToVBO(Obj3D* obj3D)
{
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
					vts.push_back(vt->x);
					vts.push_back(vt->y);
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
