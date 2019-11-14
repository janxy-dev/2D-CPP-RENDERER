#include"../Headers/Renderer.h"

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) {
	shader.Bind();
	va.Bind();
	ib.Bind();

	call(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}