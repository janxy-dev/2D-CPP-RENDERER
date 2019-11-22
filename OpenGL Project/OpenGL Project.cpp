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
#include "Headers/RectangleShape.h"
#include "Headers/Variables.h"

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
	window = glfwCreateWindow(s_width, s_height, "OpenGL", NULL, NULL); //WIDTH: 640, HEIGHT: 480
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

		float red = 0.1f;
		float i = 0.01f;

		Renderer renderer;

		RectangleShape rectangle(200.0f, 200.0f, glm::vec2(50.0f, 50.0f));
		rectangle.Scale(glm::vec2(0.5f, 0.5f));
		rectangle.SetPosition(s_width/2, s_height/2);
		rectangle.SetPosition(0.0f, 0.0f);
		rectangle.SetPosition(50.0f, 50.0f);
		rectangle.Rotate(45);
		rectangle.SetTexture("Resources/wall.jpg");

		while (!glfwWindowShouldClose(window))
		{

			renderer.Clear();
			rectangle.SetPosition(rectangle.GetPosition().x + 1, rectangle.GetPosition().y);

			renderer.Draw(rectangle);
			


			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		//glDeleteProgram(shader.GetShader());
	}
	glfwTerminate();
	return 0;
}
