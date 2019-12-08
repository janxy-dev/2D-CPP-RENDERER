#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <fstream>
#include <string>
#include <iostream>

#include "Headers/Renderer.h"
#include "Headers/VertexBuffer.h"
#include "Headers/IndexBuffer.h"
#include "Headers/VertexArray.h"
#include "Headers/Shader.h"
#include "Headers/Texture.h"
#include "Headers/RectangleShape.h"
#include "Headers/Variables.h"
#include "Headers/PolygonShape.h"
#include "Headers/ResourceManager.h"
#include "Headers/Collisions.h"
#include "Headers/Events.h"
#include "Headers/Sprite.h"

using namespace std;
typedef ResourceManager rm;

void say() {
	std::cout << "OK" << std::endl;
}

int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow((int)s_width, (int)s_height, "OpenGL", NULL, NULL); //WIDTH: 640, HEIGHT: 480
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewInit();

	cout << glGetString(GL_VERSION) << endl;

	{
        rm::LoadTexture("Resources/Assets/Spaceships/01/Spaceship_01_GREEN.png", "player");
		rm::LoadTexture("Resources/Assets/Spaceships/01/Spaceship_01_RED.png", "enemy");
		rm::LoadTexture("Resources/Assets/background.png", "background");
		rm::LoadTexture("Resources/Assets/Flame_01.png", "flame");

		RectangleShape background(s_width, s_height, s_width / 2, s_height / 2);
		background.SetTexture("background");

		Sprite player(s_width / 2, s_height / 2 + 150.0f, "player", glm::vec2(0.25f));
		Sprite enemy(s_width / 2, s_height / 2 - 150.0f, "enemy", glm::vec2(0.25f));
		std::vector<std::shared_ptr<Sprite>> ammo;
		bool readyToFire = true;
		bool enemyRightDir = true;
		bool win = false;
		while (!glfwWindowShouldClose(window))
		{
			Renderer::Clear();
			
			if (!win) {

				if (enemy.GetPosition().x > s_width) {
					enemyRightDir = false;
				}
				if (enemy.GetPosition().x < 0) {
					enemyRightDir = true;
				}

				if (enemyRightDir) {
					enemy.Translate(glm::vec2(5.0f, 0.0f));
				}
				else {
					enemy.Translate(glm::vec2(-5.0f, 0.0f));
				}
			}

			if (Events::GetKeyState(GLFW_KEY_D)) {
				player.Translate(glm::vec2(5.0f, 0.0f));
			}
			if (Events::GetKeyState(GLFW_KEY_A)) {
				player.Translate(glm::vec2(-5.0f, 0.0f));
			}
			if (Events::GetKeyState(GLFW_KEY_SPACE)) {
				if (readyToFire) {
					std::cout << player.GetPosition().x << std::endl;
					std::shared_ptr<Sprite> flame = std::make_shared<Sprite>(player.GetPosition().x, player.GetPosition().y-50.0f, "flame", glm::vec2(0.25f));
					flame->ScaleCollisionBounds(glm::vec2(0.2f, 0.2f));
					ammo.push_back(flame);
					readyToFire = false;
				}
			}
			if (!Events::GetKeyState(GLFW_KEY_SPACE)) {
				readyToFire = true;
			}

			Renderer::Draw(background);
			if (ammo.size() > 0) {
				for (unsigned int i = 0; i < ammo.size(); i++) {
					auto& bullet = ammo[i];
					Renderer::Draw(*bullet);
					if (Collisions::CheckCollision(enemy.GetCollisionBounds(), bullet->GetCollisionBounds()) && !win) {
						enemy.~Sprite();
						win = true;
					}
					bullet->Translate(glm::vec2(0.0f, -10.0f));
					if (bullet->GetPosition().y < 0) {
						std::vector<std::shared_ptr<Sprite>>::iterator it = ammo.begin() + i;
						ammo.erase(it);
					}
				}
			}
			Renderer::Draw(player);
			if (!win) { Renderer::Draw(enemy); }
			
			glfwSwapBuffers(window);
			glfwPollEvents();
			Events::KeyCallBack(window);
		}
		rm::DeleteAllShaders();
	}
	glfwTerminate();
	return 0;
}
