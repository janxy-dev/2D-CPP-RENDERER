#pragma once
#include<iostream>
#include <vector>
#include<GLM/glm.hpp>
#include "../Headers/Shader.h"
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"
#include "../Headers/ResourceManager.h"

typedef ResourceManager rm;

enum class BoundsType {
	RECTANGLE = 0, CIRCLE = 1
};

struct Bounds {
	glm::vec2 size;
	const glm::vec2& pos;
	BoundsType type;
};

class Shape {
public:
	Shape(float* vertices, unsigned int* indices, float width, float height, glm::vec2 position, const VertexArray& va, unsigned int count);
	~Shape();
	void SetTexture(const char* name);
	void Scale(glm::vec2 times);
	void Rotate(float angle);
	void SetPosition(float posx, float posy);
	glm::vec2 GetPosition() const { return position; };
	glm::vec2 GetSize() const { return size; }
	void Translate(glm::vec2 vec);
	unsigned int* GetIndices() { return indices; }
	float* GetVertices() { return vertices; }
	const Shader& GetShader() const { return *shader; }
	Texture& GetTexture() const { return *texture; };
	bool HasTexture() const { return hastexture; }
	Bounds GetCollisionBounds() const { return collisionBounds; }
	const VertexArray& GetVertexArray() const { return va; }
	unsigned int GetID() { return va.GetRendID(); }
	void ScaleCollisionBounds(glm::vec2 times);
	void SetCollisisionBoundsType(BoundsType type);
	unsigned int GetElementCount() const { return elementCount; }
	void FillColor(float a, float b, float c, float d);
	bool IsPolygon() const { return isPolygon; }
	void SetPolygon(bool a) { isPolygon = a; }
	static unsigned int instance;
private:
	float* vertices;
	unsigned int* indices;
	const VertexArray& va;
	std::shared_ptr<Shader> shader;
	glm::vec2 position = glm::vec2(0.0f);
	glm::vec2 size = glm::vec2(1.0);
	glm::mat4 model = glm::mat4(1.0f);
	std::shared_ptr<Texture> texture;
	float rotation = 0;
	bool hastexture = false;
	bool isPolygon = false;
	Bounds collisionBounds = { glm::vec2(1.0), position, BoundsType::RECTANGLE };
	unsigned int elementCount;
};
