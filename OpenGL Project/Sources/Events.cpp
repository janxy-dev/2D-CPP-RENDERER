#include "../Headers/Events.h"

std::map<int, bool> Events::keys;

bool Events::GetKeyState(int key) {
	return keys[key];
}

void Events::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
}

void Events::KeyCallBack(GLFWwindow* window) {
	glfwSetKeyCallback(window, key_callback);
}