#include "StructureTest.h"


Obj3D* StructureTest::HardcodedCube()
{
	//Face
	Face* face0 = new Face();
	face0->addInfo(0, -1, -1);
	face0->addInfo(1, -1, -1);
	face0->addInfo(2, -1, -1);

	Face* face1 = new Face();
	face1->addInfo(2, -1, -1);
	face1->addInfo(1, -1, -1);
	face1->addInfo(3, -1, -1);

	Face* face2 = new Face();
	face2->addInfo(2, -1, -1);
	face2->addInfo(3, -1, -1);
	face2->addInfo(4, -1, -1);

	Face* face3 = new Face();
	face3->addInfo(4, -1, -1);
	face3->addInfo(3, -1, -1);
	face3->addInfo(5, -1, -1);

	Face* face4 = new Face();
	face4->addInfo(4, -1, -1);
	face4->addInfo(5, -1, -1);
	face4->addInfo(6, -1, -1);

	Face* face5 = new Face();
	face5->addInfo(6, -1, -1);
	face5->addInfo(5, -1, -1);
	face5->addInfo(7, -1, -1);

	Face* face6 = new Face();
	face6->addInfo(6, -1, -1);
	face6->addInfo(7, -1, -1);
	face6->addInfo(0, -1, -1);

	Face* face7 = new Face();
	face7->addInfo(0, -1, -1);
	face7->addInfo(7, -1, -1);
	face7->addInfo(1, -1, -1);

	Face* face8 = new Face();
	face8->addInfo(1, -1, -1);
	face8->addInfo(7, -1, -1);
	face8->addInfo(3, -1, -1);

	Face* face9 = new Face();
	face9->addInfo(3, -1, -1);
	face9->addInfo(7, -1, -1);
	face9->addInfo(5, -1, -1);

	Face* face10 = new Face();
	face10->addInfo(6, -1, -1);
	face10->addInfo(0, -1, -1);
	face10->addInfo(4, -1, -1);

	Face* face11 = new Face();
	face11->addInfo(4, -1, -1);
	face11->addInfo(0, -1, -1);
	face11->addInfo(2, -1, -1);

	//Group
	vector<Face*> faces = vector<Face*>();
	faces.push_back(face0);
	faces.push_back(face1);
	faces.push_back(face2);
	faces.push_back(face3);
	faces.push_back(face4);
	faces.push_back(face5);
	faces.push_back(face6);
	faces.push_back(face7);
	faces.push_back(face8);
	faces.push_back(face9);
	faces.push_back(face10);
	faces.push_back(face11);

	Group* group = new Group();
	group->initializeGroup("group", "material", faces);

	//Mesh
	glm::vec3* zero = new glm::vec3(-0.5f, -0.5f, 0.5f); //0
	glm::vec3* one = new glm::vec3(0.5f, -0.5f, 0.5f); //1
	glm::vec3* two = new glm::vec3(-0.5f, 0.5f, 0.5f); //2
	glm::vec3* three = new glm::vec3(0.5f, 0.5f, 0.5f); //3
	glm::vec3* four = new glm::vec3(-0.5f, 0.5f, -0.5f); //4
	glm::vec3* five = new glm::vec3(0.5f, 0.5f, -0.5f); //5
	glm::vec3* six = new glm::vec3(-0.5f, -0.5f, -0.5f); //6
	glm::vec3* seven = new glm::vec3(0.5f, -0.5f, -0.5f); //7

	vector<glm::vec3*> vertex = vector<glm::vec3*>();
	vertex.push_back(zero);
	vertex.push_back(one);
	vertex.push_back(two);
	vertex.push_back(three);
	vertex.push_back(four);
	vertex.push_back(five);
	vertex.push_back(six);
	vertex.push_back(seven);

	glm::vec3* zeroN = new glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3* oneN = new glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3* twoN = new glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3* threeN = new glm::vec3(0.0f, -1.0f, 0.0f);
	glm::vec3* fourN = new glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3* fiveN = new glm::vec3(-1.0f, 0.0f, 0.0f);

	vector<glm::vec3*> norms = vector<glm::vec3*>();
	norms.push_back(zeroN);
	norms.push_back(oneN);
	norms.push_back(twoN);
	norms.push_back(threeN);
	norms.push_back(fourN);
	norms.push_back(fiveN);

	glm::vec2* zeroT = new glm::vec2(0.0f, 0.0f);
	glm::vec2* oneT = new glm::vec2(1.0f, 0.0f);
	glm::vec2* twoT = new glm::vec2(0.0f, 1.0f);
	glm::vec2* threeT = new glm::vec2(1.0f, 1.0f);

	vector<glm::vec2*> texts = vector<glm::vec2*>();
	texts.push_back(zeroT);
	texts.push_back(oneT);
	texts.push_back(twoT);
	texts.push_back(threeT);

	vector<Group*> groups = vector<Group*>();
	groups.push_back(group);

	Mesh* mesh = new Mesh();
	glm::vec3* min = new glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3* max = new glm::vec3(1.0f, 1.0f, 1.0f);
	mesh->addInfo("mtllib", min, max, vertex, norms, texts, groups);

	//Obj3D
	Obj3D* obj3D = new Obj3D();
	obj3D->addInfo(mesh, glm::mat4() /*identitiy matrix*/, 1, false, glm::vec3(0, 0, 0));

	return obj3D;
}
