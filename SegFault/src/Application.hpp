#pragma once

#include <string>

int main(int argc, char* argv[]);

namespace SegFault
{

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

};

}