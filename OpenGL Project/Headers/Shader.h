#pragma once
#include <iostream>
#include<string>
#include"../Headers/ErrorHandler.h"
#include <GL/glew.h>

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
public:
	Shader(const std::string& path);
	ShaderSrc GetShaderSource(const std::string& path);
	inline unsigned int GetShader() const { return _id; }
	void Bind() const;
	void UnBind() const;
	std::string pth;
	std::string GetPath() const {
		return pth;
	}

	void SetUniform4f(const char* name, float a, float b, float c, float d);
	void SetUniform2f(const char* name, float a, float b);
	void SetUniform4f(const char* name, float a);

	void SetUniform1i(const char* name, int a);

	void SetUniformMatrix4fv(const char* name, unsigned int count, unsigned int transpose, const GLfloat* value);

};

