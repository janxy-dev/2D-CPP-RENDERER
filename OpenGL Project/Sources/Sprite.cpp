#include "../Headers/Sprite.h"
#include "../Headers/ResourceManager.h"

Sprite::Sprite(float x, float y, const char* name, glm::vec2 scale)
	: RectangleShape((float)rm::GetTexture(name)->GetWidth(), (float)rm::GetTexture(name)->GetWidth(), x, y) {
	SetTexture(name);
	Scale(scale);
}