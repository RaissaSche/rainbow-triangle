#include <iostream>
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

GLint WIDTH = 800, HEIGHT = 600;

const char* vertexShaderSource = "#version 400 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"uniform mat4 matrix;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = matrix * vec4(aPos, 1.0);\n"
"	ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 400 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
	"FragColor = vec4(ourColor, 1.0f);\n"
"}\n";

float dot(glm::vec2 v1, glm::vec2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

glm::vec2 getInitialPositions(float angle) {
	float radAngle = angle / 180 * 3.14159265;
	glm::vec2 initialPositions;
	initialPositions.x = glm::cos(radAngle);
	initialPositions.y = glm::sin(radAngle);
	return initialPositions;
}

glm::vec2 getNewVector(glm::vec2 inputVector,glm::vec2 normal, float angle) {
	glm::vec2 outputVector;
	glm::vec2 r2 = -inputVector;
	float dotProduct = dot(normal, r2);
	outputVector.x = 2 * normal.x * dotProduct - r2.x;
	outputVector.y = 2 * normal.y * dotProduct - r2.y;
	return outputVector;
}

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Screen saver", nullptr, nullptr);
	GLint screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed no init GLEW." << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL (versão suportada) %s\n", version);

	//- Vertex Shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//- Fragment Shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//- Link Shaders
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//- Errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLfloat vertices[] = {
		// positions         // colors
		0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
	};

	GLfloat translate[] = {
		1.0f, 0.0f, 0.0f, 0.0f,  //1 coluna
		0.0f, 1.0f, 0.0f, 0.0f,  //2 coluna
		0.0f, 0.0f, 1.0f, 0.0f,  //3 coluna
		0.25f, 0.25f, 0.0f, 1.0f //4 coluna
	};

	//- VBO
	unsigned int VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//- VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	int matrixLocation = glGetUniformLocation(shaderProgram, "matrix");
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, translate);

	float angle = 60;
	glm::vec2 speed = getInitialPositions(angle);
	float lastXPosition = 0.0f;
	float lastYPosition = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		static double previousSeconds = glfwGetTime();
		double currentSeconds = glfwGetTime();
		double elapsedSeconds = currentSeconds - previousSeconds;
		previousSeconds = currentSeconds;

		//right
		if (fabs(lastXPosition) > 1.0f) {
			speed = getNewVector(speed, glm::vec2(-1, 0), angle);
		}
		//top
		else if (fabs(lastYPosition) > 1.0f) {
			speed = getNewVector(speed, glm::vec2(0, -1), angle);
		}
		//left
		else if (fabs(lastXPosition) < -1.0f) {
			speed = getNewVector(speed, glm::vec2(1, 0), angle);
		}
		//down
		else if (fabs(lastYPosition) < -1.0f) {
			speed = getNewVector(speed, glm::vec2(0, 1), angle);
		}

		translate[12] = elapsedSeconds * speed.x + lastXPosition;
		translate[13] = elapsedSeconds * speed.y + lastYPosition;
		lastXPosition = translate[12];
		lastYPosition = translate[13];

		glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, translate);

		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// glBindVertexArray(0); // no need to unbind it every time 

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
