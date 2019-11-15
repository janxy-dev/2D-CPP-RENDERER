#pragma once
#include<iostream>
#include<string>
#include<iostream>
#include <GL/glew.h>

class Texture {
public:
	Texture(const char* path, unsigned int layer = GL_TEXTURE0);
	void Bind();
private:
	int width;
	int height;
	int nrChannels;
	unsigned int _rendID;
	std::string _path;
	unsigned int layout;
};
