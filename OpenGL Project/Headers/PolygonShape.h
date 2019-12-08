 #pragma once

#include "../Headers/Shape.h"

struct DrawablePolygonShape {
	const VertexArray& va;
};
class PolygonShape : public Shape{
public:
	PolygonShape(float radius = 100.0f, unsigned int numberOfPoints = 100, float x = 0.0f, float y = 0.0f);
	 const VertexArray& GetVertexArray() const{ return va; };
	 unsigned int GetID() const{return va.GetRendID();}
	 float* GetVertices() const{return vertices;}
	 unsigned int GetPointNumber() const{return pointNumber;}
	 int GetVertCount() const{ return vertCount; }
private:
	unsigned int pointNumber;
	float radius;
	float* vertices = nullptr;
	int vertCount = 0;
	VertexArray va;
	std::shared_ptr<VertexBuffer> vb;
};
