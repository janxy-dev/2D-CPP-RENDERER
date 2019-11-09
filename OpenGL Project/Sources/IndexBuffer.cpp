#include "../Headers/IndexBuffer.h"
#include <GL/glew.h>
#include "../Headers/ErrorHandler.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:_count(count)
{
	call(glGenBuffers(1, &_rendID));
	call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendID));
	call(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer() {
	call(glDeleteBuffers(1, &_rendID));
}

void IndexBuffer::Bind() const {
	call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendID));
}

void IndexBuffer::UnBind() const {
	call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
