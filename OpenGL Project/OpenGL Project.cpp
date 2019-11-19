#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <fstream>
#include <string>
#include <iostream>

#include "Headers/Renderer.h";
#include "Headers/VertexBuffer.h";
#include "Headers/IndexBuffer.h";
#include "Headers/VertexArray.h"
#include "Headers/Shader.h"
#include "Headers/Texture.h"
#include "Headers/ShapeRectangle.h"

using namespace std;

int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewInit();

	cout << glGetString(GL_VERSION) << endl;

	{

		float vertices[] = {
			// positions          // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 
			 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,  
			-0.5f,  0.5f, 0.0f,   0.0f, 1.0f    
		};

		unsigned int indicies[] = {
			0, 1, 2,
			0, 3, 2
		};

		//VertexArray va;

		//VertexBuffer vb(vertices, 5*4*sizeof(float));
		//va.AddBuffer(vb, 0, 3, GL_FLOAT, 5);
		//va.AddBuffer(vb, 1, 2, GL_FLOAT, 5); 

		//IndexBuffer ib(indicies, 6);

		float red = 0.1f;
		float i = 0.01f;

		Renderer renderer;

		ShapeRectangle rectangle;
		rectangle.SetTexture("Resources/wall.jpg");

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();


			renderer.Draw(rectangle);


			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		//glDeleteProgram(shader.GetShader());
	}
	glfwTerminate();
	return 0;
}
