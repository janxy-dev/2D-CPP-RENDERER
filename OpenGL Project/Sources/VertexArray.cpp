#include "../Headers/VertexArray.h"
#include <GL/glew.h>
#include "../Headers/ErrorHandler.h"
#include <iostream>

VertexArray::VertexArray(){
	(glGenVertexArrays(1, &_rendID));
}

VertexArray::~VertexArray() {

	std::cout << "VA DTOR" << std::endl;
	lcall(glDeleteVertexArrays(1, &_rendID));
}

void VertexArray::Bind() const {
	lcall(glBindVertexArray(_rendID));
}

void VertexArray::UnBind() const {
	lcall(glBindVertexArray(0));
}

void VertexArray::AddBuffer(VertexBuffer& vb, unsigned int layout, unsigned int count, unsigned int type, unsigned int stride, unsigned int pointer) {
	Bind();
	vb.Bind();
	if (object != &vb) {
		offset = 0;
	}
	if (pointer != 0) { offset = pointer; }
	if (type == GL_FLOAT) {
		glVertexAttribPointer(layout, count, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void*)(offset*sizeof(float)));
		glEnableVertexAttribArray(layout);
		object = &vb;
		
	}
	if (pointer == 0) { offset += count; }

}