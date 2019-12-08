#define STB_IMAGE_IMPLEMENTATION

#include "../Headers/Texture.h"
#include "../../Dependencies/stb_image.h"
using namespace std;
Texture::Texture(const char* path, unsigned int index)
	: _rendID(0), _path(path), width(0), height(0), nrChannels(0), layout(index)

{
	glGenTextures(1, &_rendID);
	glActiveTexture(layout);
	glBindTexture(GL_TEXTURE_2D, _rendID);

	// texture wrapping/filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (data) {
		if (nrChannels == 4) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		cout << "Failed to load a texture"<<endl;
	}
	stbi_image_free(data);
}
void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, _rendID);
}
void Texture::UnBind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}