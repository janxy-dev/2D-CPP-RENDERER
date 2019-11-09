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

using namespace std;

struct ShaderSrc
{
	string vertex;
	string fragment;
};

static ShaderSrc GetShader(const string& path) {
	ifstream stream(path);
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	string line;
	string shaders[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line)) {
		if (line == "#shader vertex") {
			type = ShaderType::VERTEX;
		}
		if (line == "#shader fragment") {
			type = ShaderType::FRAGMENT;
		}

		if (type == ShaderType::VERTEX && line != "#shader vertex") {
			shaders[0] += line + "\n";
		}
		if (type == ShaderType::FRAGMENT && line != "#shader fragment") {
			shaders[1] += line + "\n";
		}
	}

	return { shaders[0], shaders[1] };
}

static unsigned int CompileShader(unsigned int type, const string& source) {

	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	//ERROR HANDLER
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result) {

		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
		cout << message << endl;
	}
	return id;
}

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader) {

	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;

}

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

		ShaderSrc src = GetShader("Resources/Basic.shader");
		unsigned int shader = CreateShader(src.vertex, src.fragment);
		call(glUseProgram(shader));
		int location = glGetUniformLocation(shader, "_color");

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

			glUniform4f(location, red, 0.5f, 0.f, 0.f);

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
