#pragma once

#include <string>

namespace MreshEngine
{
	class FileDialogs
	{
	public:
		// These return empty string when dialog is closed.
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};
}
