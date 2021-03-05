#include <iostream>

#include "window.h"

const char* vertexShaderSource =
"#version 330 core \n"
"layout (location = 0) in vec3 aPos; \n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"} \n";

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main(void)
{
	Window mWindow(800, 600, "graphics by uijin");
	mWindow.CreateWindow();
	
	while(!glfwWindowShouldClose(mWindow.getWindow()))
	{
		processInput(mWindow.getWindow()); //input

		float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f }; //vertex data

		unsigned int VBO; //store vertices in GPU's memory
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int Vsuccess;
		char VinfoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Vsuccess);

		if(!Vsuccess)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, VinfoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << VinfoLog << std::endl;
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		int Fsuccess;
		char FinfoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Fsuccess);

		if (!Fsuccess)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, FinfoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << FinfoLog << std::endl;
		}

		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		//check fail

		glUseProgram(shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); //rendering  

		glfwSwapBuffers(mWindow.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}