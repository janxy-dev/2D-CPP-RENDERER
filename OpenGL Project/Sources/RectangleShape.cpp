#include "../Headers/RectangleShape.h"

RectangleShape::RectangleShape(float width, float height, glm::vec2 pos) : Shape(vertices, indices, width, height, pos)
{
	va.AddBuffer(vb, 0, 2, GL_FLOAT, 4);
	va.AddBuffer(vb, 1, 2, GL_FLOAT, 4);
	ib.Bind();
	
}