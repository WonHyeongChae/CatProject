#pragma once

#ifdef RAG_PLATFORM_WINDOWS

extern Ragdoll::Application* Ragdoll::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ragdoll::CreateApplication();
	app->Run();
	delete app;
}

#endif