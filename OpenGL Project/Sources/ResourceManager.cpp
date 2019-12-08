#include "../Headers/ResourceManager.h"

std::map<std::string, std::shared_ptr<Shader>> ResourceManager::shaders;
std::map<std::string, std::shared_ptr<Texture>> ResourceManager::textures;

void ResourceManager::LoadShader(const char* path, std::string name) {
	shaders[name] = std::make_shared<Shader>(path);
}
std::shared_ptr<Shader> ResourceManager::GetShader(std::string name) {
	return shaders[name];
}
void ResourceManager::LoadTexture(const char* path, std::string name) {
	textures[name] = std::make_shared<Texture>(path);
}
std::shared_ptr<Texture> ResourceManager::GetTexture(std::string name) {
	return textures[name];
}
void ResourceManager::DeleteAllShaders() {
	for (const std::pair<std::string, std::shared_ptr<Shader>> _shader : shaders) {
		const Shader& shader = *_shader.second;
		glDeleteShader(shader.GetID());
	}
}