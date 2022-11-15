#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ragdoll
{
	class RAGDOLL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

	// Core log macros
	#define RAG_CORE_TRACE(...)    ::Ragdoll::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define RAG_CORE_INFO(...)     ::Ragdoll::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define RAG_CORE_WARN(...)     ::Ragdoll::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define RAG_CORE_ERROR(...)    ::Ragdoll::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define RAG_CORE_FATAL(...)    ::Ragdoll::Log::GetCoreLogger()->fatal(__VA_ARGS__)

	// Client log macros
	#define RAG_TRACE(...)	      ::Ragdoll::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define RAG_INFO(...)	      ::Ragdoll::Log::GetClientLogger()->info(__VA_ARGS__)
	#define RAG_WARN(...)	      ::Ragdoll::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define RAG_ERROR(...)	      ::Ragdoll::Log::GetClientLogger()->error(__VA_ARGS__)
	#define RAG_FATAL(...)	      ::Ragdoll::Log::GetClientLogger()->fatal(__VA_ARGS__)
}