#pragma once
#include<GLM/glm.hpp>
#include "../Headers/RectangleShape.h"
#include "../Headers/Texture.h"

class Sprite : public RectangleShape{
public:
	Sprite(float x, float y, const char* TextureName, glm::vec2 scale = glm::vec2(1.0f));
	~Sprite() {};
};
