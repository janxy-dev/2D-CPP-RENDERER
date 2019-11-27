#include "../Headers/CircleShape.h"

CircleShape::CircleShape(float r, unsigned int pNum, glm::vec2 pos)
	:pointNumber(pNum), radius(r), Shape(nullptr, nullptr, 1.0f, 1.0f, pos)
{
	std::vector<float> vert;
	std::vector<float> coords;
	vert.push_back(0.0f);
	vert.push_back(0.0f);
	float pi = 3.14159265359f;
	for (float theta = 0.0f; theta < 2 * pi; theta+=2*pi/pNum) {
		float x = glm::cos(theta) * r;
		float y = glm::sin(theta) * r;
		vert.push_back(x);
		vert.push_back(y);

	}
	vert.push_back(glm::cos(0.0f) * r);
	vert.push_back(glm::sin(0.0f) * r);

	//TexCoords
	for (unsigned int i = 0; i < vert.size(); i+=2) {
		float x = (vert[i]/r+1)*0.5f;
		float y = (vert[i+1]/r+1)*0.5f;
		coords.push_back(x);
		coords.push_back(y);
	}
	unsigned int n = 0;
	unsigned int s = coords.size() + vert.size();
	for (unsigned int i = 2; i < s; i+=4) {
		vert.insert(vert.begin() + i, coords[n + 1]);
		vert.insert(vert.begin() + i, coords[n]);
		n += 2;
	}

	vertCount = vert.size();
	vertices = vert.data();

	vb = std::make_shared<VertexBuffer>(vertices, vertCount * sizeof(float));
	va.AddBuffer(*vb, 0, 2, GL_FLOAT, 4);
	va.AddBuffer(*vb, 1, 2, GL_FLOAT, 4);

}