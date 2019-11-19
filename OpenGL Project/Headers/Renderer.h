#pragma once
#include <GL/glew.h>
#include "../Headers/ErrorHandler.h"
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"
#include "../Headers/ShapeRectangle.h"

class Renderer {
public:

	void Draw(const ShapeRectangle& shape);
	void Clear();

};
