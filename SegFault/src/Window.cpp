#include "Window.hpp"

#include <GLFW/glfw3.h>

#ifdef SF_PLATFORM_WINDOWS

	// include glfw3native to access windows native HWND
	#define GLFW_EXPOSE_NATIVE_WIN32
	#include <GLFW/glfw3native.h>

#endif

namespace SegFault
{

uint32 Window::s_refCount = 0;

Window::Window(const WindowProps& props)
	: m_VSync(false)
	, m_handle(nullptr)
{
	if (s_refCount == 0)
	{
		// init GLFW
		if (glfwInit() == GLFW_FALSE)
		{
			std::cerr << "GLFW failed to initialize!\n";
		}

		s_refCount++;
	}

	m_handle = glfwCreateWindow(props.width, props.height, props.title.c_str(), NULL, NULL);

	if (m_handle == nullptr)
	{
		std::cerr << "GLFW Window failed to initialize!\n";
	}
}

Window::~Window()
{
	if (s_refCount == 1)
	{
		glfwTerminate();
	}

	glfwDestroyWindow(m_handle);
}

uint32 Window::getWidth() const noexcept
{
	int32 width;
	glfwGetWindowSize(m_handle, &width, NULL);
	return width;
}

uint32 Window::getHeight() const noexcept
{
	int32 height;
	glfwGetWindowSize(m_handle, NULL, &height);
	return height;
}

void Window::setVSync(bool enabled) noexcept
{
	glfwSwapInterval(enabled ? 1 : 0);
	m_VSync = enabled;
}

void Window::swapBuffers() const noexcept
{
	glfwSwapBuffers(m_handle);
}

bool Window::isVSync() const noexcept
{
	return m_VSync;
}

void* Window::getNativeHandle() const noexcept
{
	return glfwGetWin32Window(m_handle);
}

bool Window::isOpen() const noexcept
{
	return !glfwWindowShouldClose(m_handle);
}

}