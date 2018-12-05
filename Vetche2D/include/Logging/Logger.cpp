#include "Logger.h"
#include <fstream>
#include "../Game/Game.h"
#include "../Core/Initialize.h"

Vetche2D::Logger::Logger()
	: m_DispTxt(sf::Text("", m_DefaultFont, m_CharSize))
{
	m_DefaultFont.loadFromFile("../Vetche2D/res/fonts/default.ttf");
	m_DispTxt.setFillColor(sf::Color(0, 150, 255));
	m_DispTxt.setFont(m_DefaultFont);
}

Vetche2D::Logger::~Logger()
{
	std::ofstream file("logs.txt");
	file << m_Log;
	file.close();
	std::cout << "File written!" << std::endl;
}

void Vetche2D::Logger::Log(const std::string & log, void* memoryLocation)
{
	stream << std::hex << memoryLocation;
	std::string result(stream.str());

	std::string full_Log = "\n" + log + " - memory address: " + result;

	m_Log += full_Log;
	std::cout << full_Log << std::endl;
}

void Vetche2D::Logger::Log(const std::string & log)
{
	m_Log += "\n" + log;
	std::cout << log << std::endl;
}

void Vetche2D::Logger::QuickLog(const std::string & log)
{
	std::cout << "QuickLog: " << log << "\r";
	m_DispTxt.setString(log);
	m_DispTxt.setPosition(50, 50);
	game->draw(m_DispTxt);
}

void Vetche2D::Logger::QuickLog(int i)
{
	std::cout << "QuickLog: " << i << "\r";
}

void Vetche2D::Logger::QuickLog(float i)
{
	std::cout << "QuickLog: " << i << "\r";
}
