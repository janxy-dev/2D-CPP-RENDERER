#include "../Headers/VertexBuffer.h"
#include <GL/glew.h>
#include "../Headers/Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	call(glGenBuffers(1, &_rendID));
	call(glBindBuffer(GL_ARRAY_BUFFER, _rendID));
	call(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
VertexBuffer::~VertexBuffer() {
	call(glDeleteBuffers(1, &_rendID));
}

void VertexBuffer::Bind() const {
	call(glBindBuffer(GL_ARRAY_BUFFER, _rendID));
}

void VertexBuffer::UnBind() const {
	call(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
