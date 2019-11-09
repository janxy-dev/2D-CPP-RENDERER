#pragma once
class IndexBuffer
{
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	inline unsigned int GetCount() const {
		return _count;
	}

private:
	unsigned int _rendID;
	unsigned int _count;
};

