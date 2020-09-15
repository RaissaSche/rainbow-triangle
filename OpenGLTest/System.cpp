#include "System.h"
#include "ManageObj.h"
#include "Obj3D.h"
#include "StructureTest.h"


System::System()
{
}


System::~System()
{
}

int System::GLFWInit()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Sabertooth", nullptr, nullptr);

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed no init GLEW." << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	return EXIT_SUCCESS;

}

int System::OpenGLSetup()
{

	glEnable(GL_BLEND);	// Enables blending ( glBlendFunc )
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	return EXIT_SUCCESS;
}

int System::SystemSetup()
{

	coreShader = Shader("Shaders/Core/core.vert", "Shaders/Core/core.frag");
	coreShader.Use();

	return EXIT_SUCCESS;
}

void System::Run()
{

	coreShader.Use();
	//coreShader.LoadTexture("images/woodTexture.jpg", "texture1", "woodTexture");

	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	
	//eye
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	//direction
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);
	//right
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	//up
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
	
	//view
	glm::mat4 view;
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	//proj
	glm::mat4 proj = glm::mat4(1.0f);
	proj = glm::perspective(66.0f/180.f * 3.1416f, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);



	GLuint VAO;
	ManageObj* manageObj = new ManageObj();
	StructureTest* structureTest = new StructureTest();
	vector<Obj3D*> objs3D;
	Obj3D* hardcodedCube = structureTest->HardcodedCube();
	objs3D.push_back(hardcodedCube);
	manageObj->ObjToVBO(objs3D[0]);
	VAO = objs3D[0]->GetMesh()->getGroups()[0]->getVAO();

	glBindVertexArray(VAO);


	glBindVertexArray(0); // Unbind VAO

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

#pragma region Input Handling

		const float cameraSpeed = 0.05f; // adjust accordingly

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			cameraPos += cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			cameraPos -= cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}

#pragma endregion

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		coreShader.Use();

		//coreShader.UseTexture("woodTexture");

		for (Obj3D* obj : objs3D) {
			Mesh* mesh = obj->GetMesh();
			int loc = glGetUniformLocation(coreShader.program, "model");
			glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(obj->getTransform()));
			for (Group* g : mesh->getGroups()) {
				glBindVertexArray(g->getVAO());
				//Material *material = getMaterial(g->material);
				//glBindTexture(GL_TEXTURE_2D, material->tid);
				glDrawArrays(GL_TRIANGLES, 0, g->getNumOfvertices(3));
			}
		}
		glfwSwapBuffers(window);
	}
}

void System::Finish()
{
	coreShader.Delete();

	glfwTerminate();
}