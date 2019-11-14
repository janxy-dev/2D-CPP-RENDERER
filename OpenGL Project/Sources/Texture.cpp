#define STB_IMAGE_IMPLEMENTATION

#include "../Headers/Texture.h"
#include "../../Dependencies/stb_image.h"
#include<GL/glew.h>
using namespace std;

float texCords[] = {

	0.0f, 0.0f,
	0.1f, 0.0f,
	0.5f, 1.0f

};

Texture::Texture(const char* path)
	: _rendID(0), _path(path), width(0), height(0), nrChannels(0)

{

	glGenTextures(1, &_rendID);
	glBindTexture(GL_TEXTURE_2D, _rendID);

	// texture wrapping/filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		cout << "Texture loaded." << endl;;
	}
	else {
		cout << "Failed to load a texture"<<endl;
	}
	stbi_image_free(data);

	
}