#pragma once

#ifdef RAG_PLATFORM_WINDOWS

extern Ragdoll::Application* Ragdoll::CreateApplication();

int main(int argc, char** argv)
{
	Ragdoll::Log::Init();

	RAG_CORE_WARN("Initialized Log!");
	int five = 5;
	RAG_INFO("Hello! Var={0}", five);

	auto app = Ragdoll::CreateApplication();
	app->Run();
	delete app;
}

#endif