#include "../Headers/Shape.h"

Shape::Shape(float* vertices, unsigned int* indices, float width, float height, glm::vec2 pos)
	: vertices(vertices), indices(indices), position(pos)
{
	model = glm::scale(model, glm::vec3(width, height, 1.0f));
	size = glm::vec2(width, height);
	model = glm::translate(model, glm::vec3(position.x / size.x - 0.5, position.y / size.y - 0.5, 0.0f));

	shader.SetMatrix4("model", model);
	shader.SetInt("tex", 0);
	shader.SetFloat4("_color", 1.0f, 1.0f, 1.0f, 0.0f);
	Scale(glm::vec2(1.0f, -1.0f));

}

Shape::~Shape() {
}

void Shape::SetTexture(const char* path) {
	texture = std::make_shared<Texture>(path, GL_TEXTURE0);
	shader.SetInt("tex", 1);
	shader.SetInt("_texture", 0);
}

void Shape::Scale(glm::vec2 times) {
	model = glm::translate(model, glm::vec3(0.5, 0.5, 0.0f));
	model = glm::scale(model, glm::vec3(times, 1.0f));
	size = size * times;
	model = glm::translate(model, glm::vec3(-0.5, -0.5, 0.0f));
	shader.SetMatrix4("model", model);
}

void Shape::Rotate(float angle) {
	rotation = rotation + angle;
	model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f, -0.5f, 0.0f));
	shader.SetMatrix4("model", model);
}

void Shape::SetPosition(float posx, float posy) {
	glm::vec2 pos = glm::vec2(posx, posy);
	float rot = rotation;
	Rotate(-rot);
	model = glm::translate(model, glm::vec3(-position.x / size.x, -position.y / size.y, 0.0f));
	position = pos;
	model = glm::translate(model, glm::vec3(pos.x / size.x, pos.y / size.y, 0.0f));
	Rotate(rot);
	shader.SetMatrix4("model", model);
}

void Shape::Translate(glm::vec2 vec) {
	position = position + vec;
	model = glm::translate(model, glm::vec3(vec.x / size.x, vec.y / size.y, 0.0f));
	shader.SetMatrix4("model", model);
}