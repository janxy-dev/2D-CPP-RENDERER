#include<GL/glew.h>
#include<GLM/glm.hpp>
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"
#include "../Headers/Variables.h"

#pragma once

struct DrawableObject {
	const VertexArray& va;
	const IndexBuffer& ib;
	const Shader& shader;
};

class RectangleShape {
public:
	RectangleShape(float width = 100.0f, float height = 100.0f, glm::vec2 pos = glm::vec2(0.0f, 0.0f));
	~RectangleShape();
	DrawableObject GetObjects() const {
		return { va, ib, shader };
	}
	unsigned int GetID() {
		return GetObjects().va.GetRendID();
	}
	unsigned int* GetIndices() {
		return indices;
	}

	float* GetVertices() {
		return vertices;
	}
	void SetTexture(const char* path);
	void Scale(glm::vec2 times);
	void Rotate(float angle);
	void SetPosition(float posx, float posy);
	glm::vec2 GetPosition();
private:

	float vertices[16] = {
		// Pos      // Tex
		0.0f, 1.0f,  0.0f, 1.0f,
		1.0f, 1.0f,  1.0f, 1.0f,
		1.0f, 0.0f,  1.0f, 0.0f,
		0.0f, 0.0f,  0.0f, 0.0f,
	};

	unsigned int indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	Shader shader{ Shader("Resources/Rectangle.shader") };
	VertexArray va;
	VertexBuffer vb = { GetVertices(), 4 * 4 * sizeof(float) };
	IndexBuffer ib{ IndexBuffer(indices, 6) };
	glm::vec2 position;
	glm::vec2 size = glm::vec2(1.0);
	glm::mat4 model = glm::mat4(1.0f);
	
};

