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

#define BIT(x) (1 << x)