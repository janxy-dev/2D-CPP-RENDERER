#pragma once
class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
	unsigned int inline const getRendererID() {
		return _rendID;
	}
private:
	unsigned int _rendID;
};

