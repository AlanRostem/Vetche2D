#include "JSONParser.h"
#include <experimental/filesystem>

namespace rj = rapidjson;

namespace Vetche2D {
	
	JSONParser::JSONParser()
		: m_JSONFileChar("")
	{

	}

	JSONParser::~JSONParser()
	{
	}

	const char * const & JSONParser::LoadJSONToCharPtr(const char * file_path)
	{
		m_InputStream = std::ifstream(file_path);
		if (!m_InputStream)
		{
			std::cout << "Failed to load JSON file!" << std::endl;
			return m_JSONFileChar;
		}
		m_JSONFileStr = std::string((std::istreambuf_iterator<char>(m_InputStream)),
									(std::istreambuf_iterator<char>()));
		m_JSONFileChar = m_JSONFileStr.c_str();
		return m_JSONFileChar;
	}


	rj::Document JSONParser::JSONObject()
	{
		//std::cout << std::experimental::filesystem::current_path().string() << std::endl;

		rj::Document document;
		document.Parse(LoadJSONToCharPtr("test.json"));

		return document;
	}
}