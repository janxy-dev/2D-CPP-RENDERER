#pragma once
#include<iostream>
#include<string>
#include<iostream>

class Texture {
public:
	Texture(const char* path);
private:
	int width;
	int height;
	int nrChannels;
	unsigned int _rendID;
	std::string _path;
};
