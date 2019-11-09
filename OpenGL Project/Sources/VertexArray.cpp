#include <iostream>
#include "../Headers/Renderer.h"
#include "../Headers/VertexArray.h"
#include "../Headers/VertexBuffer.h"

VertexArray::VertexArray() {
	call(glGenVertexArrays(1, &_rendID));
}

VertexArray::~VertexArray() {
	call(glDeleteVertexArrays(1, &_rendID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	call(glBindVertexArray(_rendID));
}

void VertexArray::UnBind() const
{
	call(glBindVertexArray(0));
}
