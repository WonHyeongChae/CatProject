#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"

namespace Ragdoll
{
	class RAGDOLL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}