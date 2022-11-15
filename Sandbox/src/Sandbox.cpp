#include <Ragdoll.h>

class Sandbox : public Ragdoll::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Ragdoll::Application* Ragdoll::CreateApplication()
{
	return new Sandbox();
}