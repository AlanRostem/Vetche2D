#pragma once
#include "../Core/Engine.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>
#include <fstream>

namespace Vetche2D {
	class JSONParser
	{
	public:
		JSONParser();
		~JSONParser();
		const char* const & LoadJSONToCharPtr(const char* file_path);
		rapidjson::Document JSONObject();
	private:
		std::ifstream m_InputStream;
		std::string m_JSONFileStr;
		const char* m_JSONFileChar;
	};
}