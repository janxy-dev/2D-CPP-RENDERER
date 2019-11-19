#include"../Headers/Renderer.h"

void Renderer::Draw(const ShapeRectangle& shape) {
	
	shape.GetObjects().shader.Bind();
	shape.GetObjects().va.Bind();
	shape.GetObjects().ib.Bind();

	lcall(glDrawElements(GL_TRIANGLES, shape.GetObjects().ib.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}