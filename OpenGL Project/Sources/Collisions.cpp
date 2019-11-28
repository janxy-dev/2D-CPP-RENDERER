#include "../Headers/Collisions.h"
#include<iostream>
bool Collisions::CheckCollision(Bounds bounds1, Bounds bounds2) {
	glm::vec2 pos1 = bounds1.pos;
	glm::vec2 size1 = bounds1.size;
	glm::vec2 pos2 = bounds2.pos;
	glm::vec2 size2 = bounds2.size;
	bool rightside = pos1.x + size1.x / 2 >= pos2.x - size2.x / 2;
	bool leftside = pos1.x - size1.x / 2 <= pos2.x + size2.x / 2;
	bool bottomside = pos1.y + size1.y / 2 >= pos2.y - size2.y / 2;
	bool topside = pos1.y - size1.y / 2 <= pos2.y + size2.y / 2;

	bool result = rightside && leftside && bottomside && topside;
	return result;
}