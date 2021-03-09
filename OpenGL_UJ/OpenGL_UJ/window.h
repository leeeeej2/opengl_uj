#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
	Window(int W, int H, std::string T);
	~Window();
	int CreateWindow();
	GLFWwindow* getWindow();
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
	int width;
	int height;
	std::string title;
	GLFWwindow* window;
};
