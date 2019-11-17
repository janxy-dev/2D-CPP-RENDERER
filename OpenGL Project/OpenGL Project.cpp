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
			// positions          // colors           // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,  
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    
		};

		unsigned int indicies[] = {
			0, 1, 2,
			0, 3, 2
		};

		VertexArray va;

		VertexBuffer vb(vertices, 8*4*sizeof(float));
		va.AddBuffer(vb, 0, 3, GL_FLOAT, 8);
		va.AddBuffer(vb, 1, 3, GL_FLOAT, 8); 
		va.AddBuffer(vb, 2, 2, GL_FLOAT, 8);

		IndexBuffer ib(indicies, 6);

		Shader shader("Resources/Shader.shader");

		Texture texture("Resources/wall.jpg", GL_TEXTURE0);
		Texture texture2("Resources/logo.png", GL_TEXTURE1);



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
			shader.SetUniform1i("_texture", 0);
			shader.SetUniform1i("_texture2", 1);

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

			shader.SetUniformMatrix4fv("transform", 1, GL_FALSE, glm::value_ptr(trans));
			Renderer::Draw(va, ib, shader);
			


			/* Swap front and back buffers */
			glfwSwapBuffers(window);
			/* Poll for and process events */
			glfwPollEvents();
		}

		glDeleteProgram(shader.GetShader());
	}
	glfwTerminate();
	return 0;
}
