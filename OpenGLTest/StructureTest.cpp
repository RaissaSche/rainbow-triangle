#include "StructureTest.h"


Obj3D* StructureTest::HardcodedCube()
{
	//Face
	vector<int> verts0{ 0, 1, 2 };
	Face* face0 = new Face(verts0, verts0.size());

	vector<int> verts1{ 3, 0, 4 };
	Face* face1 = new Face(verts1, verts1.size());

	vector<int> verts2{ 5, 0, 6 };
	Face* face2 = new Face(verts2, verts2.size());

	vector<int> verts3{ 3, 6, 0 };
	Face* face3 = new Face(verts3, verts3.size());

	vector<int> verts4{ 0, 2, 4 };
	Face* face4 = new Face(verts4, verts4.size());

	vector<int> verts5{ 5, 1, 0 };
	Face* face5 = new Face(verts5, verts5.size());

	vector<int> verts6{ 2, 1, 5 };
	Face* face6 = new Face(verts6, verts6.size());

	vector<int> verts7{ 7, 6, 3 };
	Face* face7 = new Face(verts7, verts7.size());

	vector<int> verts8{ 6, 7, 5 };
	Face* face8 = new Face(verts8, verts8.size());

	vector<int> verts9{ 7, 3, 4 };
	Face* face9 = new Face(verts9, verts9.size());

	vector<int> verts10{ 7, 4, 2 };
	Face* face10 = new Face(verts10, verts10.size());

	vector<int> verts11{ 7, 2, 5 };
	Face* face11 = new Face(verts11, verts11.size());

	//Group
	vector<Face*> faces = { face0, face1, face2, face3, face4, face5, face6, face7, face8, face9, face10, face11 };
	Group* group = new Group("group", "material", faces);

	//Mesh
	glm::vec3 zero = glm::vec3(-1.0f, -1.0f, -1.0f); //0
	glm::vec3 one = glm::vec3(-1.0f, -1.0f, 1.0f); //1
	glm::vec3 two = glm::vec3(-1.0f, 1.0f, 1.0f); //2
	glm::vec3 three = glm::vec3(1.0f, 1.0f, -1.0f); //3
	glm::vec3 four = glm::vec3(-1.0f, 1.0f, -1.0f); //4
	glm::vec3 five = glm::vec3(1.0f, -1.0f, 1.0f); //5
	glm::vec3 six = glm::vec3(1.0f, -1.0f, -1.0f); //6
	glm::vec3 seven = glm::vec3(1.0f, 1.0f, 1.0f); //7

	vector<glm::vec3*> vertex{
		&zero, &one, &two, &three,
		&four, &five, &six, &seven
	};

	vector<Group*> groups{ group };
	glm::vec3 emptyVec3 = glm::vec3(0.0f, 0.0f, 0.0f);
	vector<glm::vec3*> norms{ 3, &emptyVec3 };


	Mesh* mesh = new Mesh("mtllib", glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), vertex, groups);

	//Obj3D
	Obj3D* obj3D = new Obj3D(mesh, glm::mat4() /*identitiy matrix*/, 1, false, glm::vec3(0, 0, 0));

	return obj3D;
}

/*
vector<glm::vec3*> vertex = {
	-1.0f,-1.0f,-1.0f, //0
	-1.0f,-1.0f, 1.0f, //1
	-1.0f, 1.0f, 1.0f, //2
	1.0f, 1.0f,-1.0f, //3
	-1.0f,-1.0f,-1.0f, //0
	-1.0f, 1.0f,-1.0f, //4
	1.0f,-1.0f, 1.0f, //5
	-1.0f,-1.0f,-1.0f, //0
	1.0f,-1.0f,-1.0f, //6
	1.0f, 1.0f,-1.0f, //3
	1.0f,-1.0f,-1.0f, //6
	-1.0f,-1.0f,-1.0f, //0
	-1.0f,-1.0f,-1.0f, //0
	-1.0f, 1.0f, 1.0f, //2
	-1.0f, 1.0f,-1.0f, //4
	1.0f,-1.0f, 1.0f, //5
	-1.0f,-1.0f, 1.0f, //1
	-1.0f,-1.0f,-1.0f, //0
	-1.0f, 1.0f, 1.0f, //2
	-1.0f,-1.0f, 1.0f, //1
	1.0f,-1.0f, 1.0f, //5
	1.0f, 1.0f, 1.0f, //7
	1.0f,-1.0f,-1.0f, //6
	1.0f, 1.0f,-1.0f, //3
	1.0f,-1.0f,-1.0f, //6
	1.0f, 1.0f, 1.0f, //7
	1.0f,-1.0f, 1.0f, //5
	1.0f, 1.0f, 1.0f, //7
	1.0f, 1.0f,-1.0f, //3
	-1.0f, 1.0f,-1.0f, //4
	1.0f, 1.0f, 1.0f, //7
	-1.0f, 1.0f,-1.0f, //4
	-1.0f, 1.0f, 1.0f, //2
	1.0f, 1.0f, 1.0f, //7
	-1.0f, 1.0f, 1.0f, //2
	1.0f,-1.0f, 1.0f //5
	};
*/

