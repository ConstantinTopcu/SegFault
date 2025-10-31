#include "Application.hpp"
#include <chrono>
#include <iostream>


SegFault::Application::Application(const std::string& name)
	: m_running(true)
{

}

SegFault::Application::~Application()
{

}

// Start main loop
void SegFault::Application::run()
{
	auto lastFrameTime = std::chrono::high_resolution_clock::now();

	while (m_running)
	{
		auto currentFrameTime = std::chrono::high_resolution_clock::now(); 
		std::chrono::duration<double> deltaTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		std::cout << (int) (1.0 / deltaTime.count()) << std::endl;
	}

}