#include <iostream>
#include "window.h"

Window::Window(int W, int H, std::string T) : width(W), height(H), title(T)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/*glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/ //using this in mac OS X
}

Window::~Window()
{
}

int Window::CreateWindow()
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);
	return 0;
}

GLFWwindow* Window::getWindow()
{
	return window;
}
