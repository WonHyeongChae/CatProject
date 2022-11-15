#include "ragpch.h"

#include "Application.h"

#include "Ragdoll/Events/ApplicationEvent.h"
#include "Ragdoll/Log.h"

namespace Ragdoll 
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RAG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RAG_TRACE(e);
		}

		while (true);
	}
}