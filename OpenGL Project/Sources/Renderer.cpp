#include"../Headers/Renderer.h"
#include <algorithm>

std::vector<Shape> Renderer::shapes;

void Renderer::Draw(const Shape& shape) {
	shape.GetShader().Bind();
	shape.GetVertexArray().Bind();
	if (shape.HasTexture()) { shape.GetTexture().Bind(); }

	if (shape.IsPolygon()) {
		lcall(glDrawArrays(GL_TRIANGLE_FAN, 0, shape.GetElementCount()));
	}
	else {
		lcall(glDrawElements(GL_TRIANGLES, shape.GetElementCount(), GL_UNSIGNED_INT, nullptr));
	}

}
void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}