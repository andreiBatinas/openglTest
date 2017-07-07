#include <iostream>
#include "GL\glew.h"
#include "GLFW\glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to creare window " << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "Error: " << glewGetErrorString(err) << std::endl;
	}
	std::cout << "Using Glew version " << glewGetString(GLEW_VERSION) << std::endl;

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//render loop
	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);

		//render commands
		glClearColor(0.2f, 0.3f, 0.3, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//check for events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
	std::cout << "width: " << width << " " << "height: " << height << std::endl;
}

void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}