#pragma once
#include <iostream>
#include<map>
#include <string>
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"

class ResourceManager {

public:
	static std::map<std::string, std::shared_ptr<Shader>> shaders;
	static std::map<std::string, std::shared_ptr<Texture>> textures;

	static void LoadShader(const char* path, std::string name);

	static std::shared_ptr<Shader> GetShader(std::string name);
	static std::map<std::string, std::shared_ptr<Shader>> GetShaders() {
		return shaders;
	}
	static void LoadTexture(const char* path, std::string name);
	static std::shared_ptr<Texture> GetTexture(std::string name);
	static std::map<std::string, std::shared_ptr<Texture>> GetTextures() {
		return textures;
	}
	static void DeleteAllShaders();
private:
	ResourceManager();
};
