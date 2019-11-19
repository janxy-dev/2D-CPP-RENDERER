#include "../Headers/ShapeRectangle.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include <iostream>

ShapeRectangle::ShapeRectangle(float height, float width, glm::vec2 pos)
{
	shader.Bind();
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	shader.SetUniformMatrix4fv("transform", 1, GL_FALSE, glm::value_ptr(trans));

	va.AddBuffer(vb, 0, 3, GL_FLOAT, 5);
	va.AddBuffer(vb, 1, 2, GL_FLOAT, 5);

	ib.Bind();

}
ShapeRectangle::~ShapeRectangle() {
}

unsigned int* ShapeRectangle::GetIndicies() {
	return indicies;
}

float* ShapeRectangle::GetVertices() {
	return vertices;
}

void ShapeRectangle::SetTexture(const char* path) {
	Texture texture(path, GL_TEXTURE0);
}


