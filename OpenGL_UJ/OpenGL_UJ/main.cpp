#include "window.h"

int main(void)
{
	Window mWindow(800, 600, "graphics by uijin");
	mWindow.CreateWindow();
	
	while(!glfwWindowShouldClose(mWindow.getWindow()))
	{
		glfwSwapBuffers(mWindow.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}