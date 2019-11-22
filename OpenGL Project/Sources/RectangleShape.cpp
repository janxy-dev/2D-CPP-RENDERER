#include "../Headers/RectangleShape.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include <iostream>

RectangleShape::RectangleShape(float width, float height, glm::vec2 pos)
	:position(pos)
{
	
	shader.Bind();

	model = glm::translate(model, glm::vec3(position, 0.0f));

	model = glm::scale(model, glm::vec3(width, height, 1.0f));
	size = glm::vec2(width, height);
	


	shader.SetMatrix4("model", model);
	shader.SetInt("tex", 0);
	shader.SetFloat4("_color", 1.0f, 1.0f, 1.0f, 0.0f);

	va.AddBuffer(vb, 0, 2, GL_FLOAT, 4);
	va.AddBuffer(vb, 1, 2, GL_FLOAT, 4);

	ib.Bind();
}
RectangleShape::~RectangleShape() {

}

void RectangleShape::SetTexture(const char* path) {
	Texture texture(path, GL_TEXTURE0);
	shader.SetInt("tex", 1);
	shader.SetInt("_texture", 0);
}

void RectangleShape::Scale(glm::vec2 times) {
	size = size * times;
	model = glm::scale(model, glm::vec3(times, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f, -0.5f, 0.0f));
	shader.SetMatrix4("model", model);
}

void RectangleShape::Rotate(float angle) {
	model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f, -0.5f, 0.0f));
	shader.SetMatrix4("model", model);
}

void RectangleShape::SetPosition(float posx, float posy) {
	glm::vec2 pos = glm::vec2(posx, posy);
	model = glm::translate(model, glm::vec3( -position.x/size.x, -position.y/size.y, 0.0f));
	position = pos;
	model = glm::translate(model, glm::vec3(pos.x/size.x, pos.y/size.y, 0.0f));
	shader.SetMatrix4("model", model);
}

glm::vec2 RectangleShape::GetPosition() {
	return position;
}


