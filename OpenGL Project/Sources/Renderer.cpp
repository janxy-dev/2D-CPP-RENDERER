#include"../Headers/Renderer.h"
void Renderer::Draw(const RectangleShape& shape) {
	
	shape.GetShader().Bind();
	shape.GetVertexArray().Bind();
	shape.GetTexture().Bind();

	lcall(glDrawElements(GL_TRIANGLES, shape.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr));

}
void Renderer::Draw(const CircleShape& shape) {
	shape.GetShader().Bind();
	shape.GetVertexArray().Bind();
	shape.GetTexture().Bind();

	lcall(glDrawArrays(GL_TRIANGLE_FAN, 0, shape.GetVertCount()));
}
void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}