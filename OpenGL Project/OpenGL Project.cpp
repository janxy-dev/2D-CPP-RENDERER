#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>

#include "Headers/Renderer.h";
#include "Headers/VertexBuffer.h";
#include "Headers/IndexBuffer.h";
#include "Headers/VertexArray.h"
#include "Headers/Shader.h"
#include "Headers/Texture.h"

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



	float colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f
	};

		float positions[] = {
		   -0.5f, -0.5f, 0.0f,   0.5f, -0.5f, 0.0f,  // 0
			0.5f,  0.5f, 0.0f,   0.5f,  0.5f, 0.0f,  // 1
		   -0.5f,  0.5f, 0.0f,  -0.5f,  0.5f, 0.0f, // 2
			0.5f, -0.5f, 0.0f,    0.5f, -0.5f, 0.0f   // 3
		};

		unsigned int indicies[] = {
			0, 1, 2,
			0, 1, 3,
		};

		VertexArray va;

		VertexBuffer vb(positions, 6*4*sizeof(float));
		va.AddBuffer(vb, 2, 3, GL_FLOAT, 6);
		va.AddBuffer(vb, 0, 3, GL_FLOAT, 6);


		IndexBuffer ib(indicies, 6);

		//va.AddBuffer(vb, 3, GL_FLOAT, 12);

		

		Shader shader("Resources/Basic.shader");
		Texture texture("Resources/wall.jpg");

		float red = 0.1f;
		float i = 0.01f;
		while (!glfwWindowShouldClose(window))
		{
			Renderer::Clear();

			if (red > 1.f) {
				i = -0.01f;
			}
			else if (red < 0.f) {
				i = 0.01f;
			}
			red += i;

			shader.SetUniform4f<float>("_color", red, 0.5f, 0.f, 0.f);
			Renderer::Draw(va, ib, shader);
			


			/* Swap front and back buffers */
			glfwSwapBuffers(window);
			/* Poll for and process events */
			glfwPollEvents();
		}

		//glDeleteProgram(shader);
	}
	glfwTerminate();
	return 0;
}
