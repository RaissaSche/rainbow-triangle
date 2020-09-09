#include "StructureTest.h"


Obj3D* StructureTest::HardcodedCube()
{
	//Face
	vector<int> verts0{ 0, 1, 2 };
	Face* face0 = new Face(verts0, verts0.size());

	vector<int> verts1{ 2, 1, 3 };
	Face* face1 = new Face(verts1, verts1.size());

	vector<int> verts2{ 2, 3, 4 };
	Face* face2 = new Face(verts2, verts2.size());

	vector<int> verts3{ 4, 3, 5 };
	Face* face3 = new Face(verts3, verts3.size());

	vector<int> verts4{ 4, 5, 6 };
	Face* face4 = new Face(verts4, verts4.size());

	vector<int> verts5{ 6, 5, 7 };
	Face* face5 = new Face(verts5, verts5.size());

	vector<int> verts6{ 6, 7, 0 };
	Face* face6 = new Face(verts6, verts6.size());

	vector<int> verts7{ 0, 7, 1 };
	Face* face7 = new Face(verts7, verts7.size());

	vector<int> verts8{ 1, 7, 3 };
	Face* face8 = new Face(verts8, verts8.size());

	vector<int> verts9{ 3, 7, 5 };
	Face* face9 = new Face(verts9, verts9.size());

	vector<int> verts10{ 6, 0, 4 };
	Face* face10 = new Face(verts10, verts10.size());

	vector<int> verts11{ 4, 0, 2 };
	Face* face11 = new Face(verts11, verts11.size());

	//Group
	vector<Face*> faces = { face0, face1, face2, face3, face4, face5, face6, face7, face8, face9, face10, face11 };
	Group* group = new Group("group", "material", faces);

	//Mesh
	glm::vec3 zero = glm::vec3(-0.5f, -0.5f, 0.5f); //0
	glm::vec3 one = glm::vec3(0.5f, -0.5f, 0.5f); //1
	glm::vec3 two = glm::vec3(-0.5f, 0.5f, 0.5f); //2
	glm::vec3 three = glm::vec3(0.5f, 0.5f, 0.5f); //3
	glm::vec3 four = glm::vec3(-0.5f, 0.5f, -0.5f); //4
	glm::vec3 five = glm::vec3(0.5f, 0.5f, -0.5f); //5
	glm::vec3 six = glm::vec3(-0.5f, -0.5f, -0.5f); //6
	glm::vec3 seven = glm::vec3(0.5f, -0.5f, -0.5f); //7

	vector<glm::vec3*> vertex{
		&zero, &one, &two, &three,
		&four, &five, &six, &seven
	};

	glm::vec3 zeroN = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 oneN = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 twoN = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 threeN = glm::vec3(0.0f, -1.0f, 0.0f);
	glm::vec3 fourN = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 fiveN = glm::vec3(-1.0f, 0.0f, 0.0f);

	vector<glm::vec3*> norms{
		&zeroN, &oneN, &twoN, &threeN, &fourN, &fiveN
	};

	glm::vec2 zeroT = glm::vec2(0.0f, 0.0f);
	glm::vec2 oneT = glm::vec2(1.0f, 0.0f);
	glm::vec2 twoT = glm::vec2(0.0f, 1.0f);
	glm::vec2 threeT = glm::vec2(1.0f, 1.0f);

	vector<glm::vec2*> texts{
	&zeroT, &oneT, &twoT, &threeT
	};

	vector<Group*> groups{ group };
	Mesh* mesh = new Mesh("mtllib", glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), vertex, norms, texts, groups);

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

