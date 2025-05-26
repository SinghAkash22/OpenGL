#include<stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;
int main()
{
	//initialise the GLFW
	if (!glfwInit())
	{
		printf("GLFW initilisation is faild");
		glfwTerminate();
		return 1;
	}
	//setup GLFW windows property
	//opengl version setup
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile = No backward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("window now created");
		glfwTerminate();
		return 1;
	}

	//get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//set the context for glew to use
	glfwMakeContextCurrent(mainWindow);

	//allow modern extention feature
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("glfw init fail");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop until window close

	while (!glfwWindowShouldClose(mainWindow))
	{
		//get + handle user input events
		glfwPollEvents(); // get all the events

		//clear window
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}