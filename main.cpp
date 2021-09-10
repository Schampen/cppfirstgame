#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Initialize GLFW
	if (!glfwInit())
		return -1;

	// Tell GLFW what version of OpenGL we are using
	// Which in this case is OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(800,800, "C++ First Game", NULL, NULL);
	// Error check incase the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Add the window to the current context
	glfwMakeContextCurrent(window);

	// Loads GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the window
	glViewport(0, 0, 800, 800);


	// Specify the background color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// assign the new color to the back buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// Change the back buffer with the front buffer
	glfwSwapBuffers(window);


	while (!glfwWindowShouldClose(window))
	{

		// Takes care of all GLFW events
		glfwPollEvents();
	}

	// Destroys the GLFW window
	glfwDestroyWindow(window);
	// Terminates GLFW before ending the program
	glfwTerminate();
	return 0;
}
