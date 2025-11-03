#pragma once

#include <iostream>
#include "Core.hpp"

struct GLFWwindow;

namespace SegFault
{

struct WindowProps
{
	std::string title;
	unsigned int width;
	unsigned int height;
};

class Window
{

public:
	Window(const WindowProps& props);
	~Window();
	
	uint32 getWidth() const noexcept;
	uint32 getHeight() const noexcept;
	bool isVSync() const noexcept;
	void* getNativeHandle() const noexcept;
	bool isOpen() const noexcept;

	void setVSync(bool enabled) noexcept;
	void swapBuffers() const noexcept;

private:
	GLFWwindow* m_handle;
	bool m_VSync;
	static uint32 s_refCount;
};
}