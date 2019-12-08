#pragma once
#include <GL/glew.h>
#include "../Headers/ErrorHandler.h"
#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/Shader.h"
#include "../Headers/RectangleShape.h"
#include "../Headers/PolygonShape.h"

class Renderer {
public:
	static void Draw(const Shape& shape);
	static void Clear();
private:
	static std::vector<Shape> shapes;
	Renderer();

};
