#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <map>

class Events {
public:
	static void KeyCallBack(GLFWwindow* window);
	static bool GetKeyState(int key);
private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static std::map<int, bool> keys;
};