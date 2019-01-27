#include "XMLParser.h"

namespace rx = rapidxml;

namespace Vetche2D {

	XMLParser::XMLParser()
	{
	
	}

	XMLParser::~XMLParser()
	{
	}

	const char * const & XMLParser::LoadXMLToCharPtr(const char * file_path)
	{
		m_InputStream = std::ifstream(file_path);
		if (!m_InputStream)
		{
			std::cout << "Failed to load XML file!" << std::endl;
			return m_XMLFileChar;
		}
		m_XMLFileStr = std::string((std::istreambuf_iterator<char>(m_InputStream)),
			(std::istreambuf_iterator<char>()));
		m_XMLFileChar = m_XMLFileStr.c_str();
		return m_XMLFileChar;
	}

	
}



