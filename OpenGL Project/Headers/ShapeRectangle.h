#include<GL/glew.h>
#include<GLM/glm.hpp>
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"

#pragma once

struct DrawableObject {
	const VertexArray& va;
	const IndexBuffer& ib;
	const Shader& shader;
};

class ShapeRectangle {
public:
	ShapeRectangle(float height = 5.0f, float width = 5.0f, glm::vec2 pos = glm::vec2(1.0, 1.0));
	~ShapeRectangle();
	unsigned int* GetIndicies();
	float* GetVertices();
	DrawableObject GetObjects() const {
		return { va, ib, shader };
	}
	unsigned int GetID() {
		return GetObjects().va.GetRendID();
	}
	void SetTexture(const char* path);
private:

	float vertices[20] = {
		// positions          // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f
	};

	unsigned int indicies[6] = {
	0, 1, 2,
	0, 3, 2
	};

	Shader shader{ Shader("Resources/Shader.shader") };

	VertexBuffer vb{ GetVertices(), 5 * 4 * sizeof(float) };
	VertexArray va;
	IndexBuffer ib{ IndexBuffer(indicies, 6) };
};

