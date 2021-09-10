#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Source code for a vertex shader
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// Source code for a fragment shader
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// Which in this case is OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// An array of vertices, a vertex is a point where two or more lines meet
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	};

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

	// Creates a shader of a defined type with the source code defined at the start of the file and compiles it into machine code to be used
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Creates a shader program
	GLuint shaderProgram = glCreateProgram();
	// Attaches the previously created shaders to the shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Links the shader program to GLFW so that we can use it
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

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
