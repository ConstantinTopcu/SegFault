#pragma once

namespace SegFault
{

class Application;

extern SegFault::Application* createApplication();

// Helper macro to help set default Application
#define SF_REGISTER_APPLICATION(AppType) \
	SegFault::Application* SegFault::createApplication() \
	{ \
		return new AppType(); \
	} \

}