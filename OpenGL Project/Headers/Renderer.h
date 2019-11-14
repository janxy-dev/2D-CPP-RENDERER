#pragma once
#include <GL/glew.h>
#include "../Headers/ErrorHandler.h"
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"

class Renderer {
public:
	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	static void Clear();
};
