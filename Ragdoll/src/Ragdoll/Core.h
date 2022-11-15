#pragma once

#ifdef RAG_PLATFORM_WINDOWS
	#ifdef RAG_BUILD_DLL
		#define RAGDOLL_API __declspec(dllexport)
	#else
		#define RAGDOLL_API __declspec(dllimport)
	#endif
#else
	#error Ragdoll only supports Windows!
#endif

#ifdef RAG_ENABLE_ASSERTS
	#define RAG_ASSERT(x, ...) { if(!(x)) { RAG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RAG_CORE_ASSERT(x, ...) { if(!(x)) { RAG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RAG_ASSERT(x, ...)
	#define RAG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)