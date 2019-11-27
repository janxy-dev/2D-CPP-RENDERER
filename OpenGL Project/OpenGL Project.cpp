#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <fstream>
#include <string>
#include <iostream>

#include "Headers/Renderer.h"
#include "Headers/VertexBuffer.h"
#include "Headers/IndexBuffer.h"
#include "Headers/VertexArray.h"
#include "Headers/Shader.h"
#include "Headers/Texture.h"
#include "Headers/RectangleShape.h"
#include "Headers/Variables.h"
#include "Headers/CircleShape.h"
#include "Headers/ResourceManager.h"

using namespace std;
typedef ResourceManager rm;

int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow((int)s_width, (int)s_height, "OpenGL", NULL, NULL); //WIDTH: 640, HEIGHT: 480
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
		rm::LoadTexture("Resources/logo.jpg", "logo");
		rm::LoadTexture("Resources/wall.jpg", "wall");
		Renderer renderer;

		RectangleShape rectangle(200.0f, 200.0f, glm::vec2(50.0f, 50.0f));
		CircleShape circle(100.0f, 100, glm::vec2(s_width/2, s_height/2));
		circle.SetTexture("logo");
		rectangle.SetTexture("wall");
		circle.Scale(glm::vec2(0.5f, 0.5f));
		

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			renderer.Draw(rectangle);
			renderer.Draw(circle);


			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		rm::DeleteAllShaders();
	}
	glfwTerminate();
	return 0;
}
