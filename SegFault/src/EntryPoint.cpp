#include "EntryPoint.hpp"
#include "Application.hpp"

// -------------- Entry Point -----------------
int main(int argc, char* argv[])
{
	SegFault::Application* app = SegFault::createApplication();
	app->run();
	delete app;

	return 0;
}