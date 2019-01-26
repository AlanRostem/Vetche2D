#pragma once
#include "rapidxml/rapidxml.hpp"
#include <iostream>
#include <string>
#include <fstream>



namespace Vetche2D {
	class XMLParser
	{
	public:
		XMLParser();
		~XMLParser();
		const char* const & LoadXMLToCharPtr(const char* file_path);
		rapidxml::xml_document<> XMLDocument();

	private:
		std::ifstream m_InputStream;
		std::string m_XMLFileStr;
		const char* m_XMLFileChar;
	};
}
