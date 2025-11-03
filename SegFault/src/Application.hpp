#pragma once

#include <string>
#include <memory>

int main(int argc, char* argv[]);

namespace SegFault
{

class Window;

class Application
{

public:

	Application(const std::string& name);
	~Application();

private:
	friend int ::main(int argc, char* argv[]);
	void run();

private:
	bool m_running;
	std::unique_ptr<Window> m_window;

};

}