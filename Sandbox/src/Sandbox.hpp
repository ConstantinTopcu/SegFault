#pragma once

#include <SegFault.hpp>

class Sandbox : public SegFault::Application
{

public:

	Sandbox()
		: SegFault::Application("Sandbox")
	{

	}

	~Sandbox()
	{

	}

private:

};

SF_REGISTER_APPLICATION(Sandbox);