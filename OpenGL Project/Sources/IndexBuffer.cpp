#include "../Headers/IndexBuffer.h"
#include <GL/glew.h>
#include "../Headers/Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:_count(count), _data(data)
{
	
	(glGenBuffers(1, &_rendID));
	lcall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendID));
	lcall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer() {

	std::cout << "IndexBuffer DTOR" <<std::endl;
	lcall(glDeleteBuffers(1, &_rendID));
}

void IndexBuffer::Bind() const {
	lcall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendID));
}

void IndexBuffer::UnBind() const {
	lcall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
