#pragma once
#include <iostream>
#include<string>
#include"Renderer.h"

struct ShaderSrc
{
	std::string vertex;
	std::string fragment;
};

class Shader {

private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int _id;
	int location;
public:
	Shader(const std::string& path);
	ShaderSrc GetShaderSource(const std::string& path);
	inline unsigned int GetShader() const { return _id; }
	void Bind() const;
	void UnBind() const;
	template<class T>
	void SetUniform4f(const char* name, T a, T b, T c, T d) {
		location = glGetUniformLocation(_id, name);
		call(glUniform4f(location, a, b, c, d));
	}

};

