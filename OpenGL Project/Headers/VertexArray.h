#pragma once
#include "../Headers/VertexBuffer.h"
#include "../Headers/VertexBufferLayout.h"

class VertexArray {

private:
	unsigned int _rendID;

public:
	VertexArray();
	~VertexArray();
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void UnBind() const;

};
