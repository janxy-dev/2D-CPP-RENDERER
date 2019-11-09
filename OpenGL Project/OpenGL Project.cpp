#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Headers/Renderer.h";
#include "Headers/VertexBuffer.h";
#include "Headers/IndexBuffer.h";
#include "Headers/VertexArray.h"
#include "Headers/VertexBufferLayout.h"
#include "Headers/Shader.h"

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

		float positions[] = {
		   -0.5f, -0.5f, //0
			0.5f,  0.5f, //1
		   -0.5f,  0.5f, //2
			0.5f, -0.5f, //3
		};

		unsigned int indicies[] = {
			0, 1, 2,
			0, 1, 3,
		};

		VertexArray va;
		VertexBuffer vb(positions, sizeof(positions));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indicies, 6);

		Shader shader("Resources/Basic.shader");


		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		float red = 0.1f;
		float i = 0.01f;
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			if (red > 1.f) {
				i = -0.01f;
			}
			else if (red < 0.f) {
				i = 0.01f;
			}
			red += i;

			shader.SetUniform4f<float>("_color", red, 0.5f, 0.f, 0.f);

			va.Bind();
			ib.Bind();

			call(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));


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
