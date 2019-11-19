#include "../Headers/VertexBuffer.h"
#include <GL/glew.h>
#include "../Headers/Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	lcall(glGenBuffers(1, &_rendID));
	lcall(glBindBuffer(GL_ARRAY_BUFFER, _rendID));
	lcall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
VertexBuffer::~VertexBuffer() {
	lcall(glDeleteBuffers(1, &_rendID));
}

void VertexBuffer::Bind() const {
	lcall(glBindBuffer(GL_ARRAY_BUFFER, _rendID));
}

void VertexBuffer::UnBind() const {
	lcall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
