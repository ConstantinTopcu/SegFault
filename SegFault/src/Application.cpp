#include "Application.hpp"
#include "Window.hpp"

#include <chrono>
#include <iostream>
#include <GLFW/glfw3.h>


SegFault::Application::Application(const std::string& name)
	: m_running(true)
{
	WindowProps windowProps = { name, 1920, 1080 };
	m_window = std::make_unique<Window>(windowProps);
}

SegFault::Application::~Application()
{

}

// Start main loop
void SegFault::Application::run()
{
	auto lastFrameTime = std::chrono::high_resolution_clock::now();

	while (m_window->isOpen())
	{
		auto currentFrameTime = std::chrono::high_resolution_clock::now(); 
		std::chrono::duration<double> deltaTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		glfwPollEvents();
	}

}