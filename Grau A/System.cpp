#include "System.h"
#include "ManageObj.h"
#include "Obj3D.h"
#include "ConfigureScene.h"


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

	ConfigureScene* configureScene = new ConfigureScene();
	configureScene->readFile("config.txt");
	width = configureScene->getWidth();
	height = configureScene->getHeight();
	cameraPos = configureScene->getCameraPos();
	cameraTarget = configureScene->getCameraTarget();
	cameraUp = configureScene->getCameraUp();
	objs = configureScene->getObjs();

	window = glfwCreateWindow(width, height, "GA - Raissa Scheeren", nullptr, nullptr);

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

	glViewport(0, 0, width, height);

	return EXIT_SUCCESS;

}

int System::OpenGLSetup()
{

	glEnable(GL_BLEND);	// Enables blending ( glBlendFunc )
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

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
	char path[] = "textures/mesa01.bmp";
	char textureUniformName[] = "texture1";
	coreShader.LoadTexture(path, textureUniformName, "woodTexture");

	//view
	glm::mat4 view;
	view = glm::lookAt(cameraPos, cameraTarget, cameraUp);

	//proj
	glm::mat4 proj = glm::mat4(1.0f);
	proj = glm::perspective(60.0f / 180.f * 3.1416f, (float)width / (float)height, 0.1f, 100.0f);

	//Teste

	
	GLuint VAO;
	int shotLocation = -1;
	ManageObj* manageObj = new ManageObj();

	//mtl file reading test
	//vector<Material*> materials = manageObj->readMtl("objs3D/mesa01.mtl");

	for (int i = 0; i < objs.size(); i++) {
		manageObj->ObjToVBO(objs[i]);
		vector<Group*> groups = objs[i]->getMesh()->getGroups();

		for (int j = 0; j < groups.size(); j++) {
			VAO = groups[j]->getVAO();

			glBindVertexArray(VAO);
			glBindVertexArray(0); // Unbind VAO
		}

		if (objs[i]->getName() == "Shot") {
			shotLocation = i;
		}
	}

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

#pragma region Input Handling

		const float cameraSpeed = 0.05f; // adjust accordingly

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			cameraPos += cameraSpeed * cameraUp;
			//cameraTarget.y += 0.1;
			//if(shotLocation != -1){
			//	objs[shotLocation]->addInfoTranslate(cameraPos.x + 1, cameraPos.y + 1, cameraPos.z + 1);
			//}
			view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			cameraPos -= cameraSpeed * cameraUp;
			//cameraTarget.y -= 0.1;
			//if(shotLocation != -1){
			//	objs[shotLocation]->addInfoTranslate(cameraPos.x + 1, cameraPos.y + 1, cameraPos.z + 1);
			//}
			view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			cameraPos -= glm::normalize(glm::cross(cameraUp, cameraPos)) * cameraSpeed;
			//cameraTarget.x += 0.1;
			//if(shotLocation != -1){
			//	objs[shotLocation]->addInfoTranslate(cameraPos.x + 1, cameraPos.y + 1, cameraPos.z + 1);
			//}
			view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			cameraPos += glm::normalize(glm::cross(cameraUp, cameraPos)) * cameraSpeed;
			//cameraTarget.x -= 0.1;
			//if(shotLocation != -1){
			//	objs[shotLocation]->addInfoTranslate(cameraPos.x + 1, cameraPos.y + 1, cameraPos.z + 1);
			//}
			view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
		}

#pragma endregion

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		coreShader.Use();
		coreShader.UseTexture("woodTexture");

		int viewU = glGetUniformLocation(coreShader.program, "view");
		glUniformMatrix4fv(viewU, 1, GL_FALSE, glm::value_ptr(view));
		int projU = glGetUniformLocation(coreShader.program, "proj");
		glUniformMatrix4fv(projU, 1, GL_FALSE, glm::value_ptr(proj));

		for (Obj3D* obj : objs) {
			Mesh* mesh = obj->getMesh();

			int loc = glGetUniformLocation(coreShader.program, "model");
			glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(obj->getTransform()));

			for (Group* g : mesh->getGroups()) {
				glBindVertexArray(g->getVAO());
				//Material *material = getMaterial(g->material);
				//glBindTexture(GL_TEXTURE_2D, material->tid);

				glDrawArrays(GL_TRIANGLES, 0, g->getNumOfvertices());
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
