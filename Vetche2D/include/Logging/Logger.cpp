#include "Logger.h"
#include <fstream>
#include "../Game/Game.h"
#include "../Core/Initialize.h"
#include "../Misc/Casting.h"

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

	std::string full_Log = "\n\n" + log + " - memory address: " + result;

	if (full_Log.size() > m_MaxCharactersPerDisplay)
	{
		for (unsigned int i = m_MaxCharactersPerDisplay; i < full_Log.size(); i += m_MaxCharactersPerDisplay)
		{
			if (i > full_Log.size())
			{
				full_Log.insert(i - full_Log.size(), "\n");
				continue;
			}
			full_Log.insert(i, "\n");
		}
	}

	m_Log += full_Log;
	AddStringToDisplay();
}

void Vetche2D::Logger::Log(const std::string & log)
{
	std::string full_Log = "\n\n" + log;
	if (full_Log.size() > m_MaxCharactersPerDisplay)
	{
		for (unsigned int i = m_MaxCharactersPerDisplay; i < full_Log.size(); i += m_MaxCharactersPerDisplay)
		{
			if (i > full_Log.size())
			{
				full_Log.insert(i - full_Log.size(), "\n");
				continue;
			}
			full_Log.insert(i, "\n");
		}
	}
	m_Log += full_Log;
	AddStringToDisplay();
}

void Vetche2D::Logger::QuickLog(const std::string & log)
{
	std::cout << "QuickLog: " << log << "\r";
}

void Vetche2D::Logger::QuickLog(int i)
{
	std::cout << "QuickLog: " << i << "\r";
}

void Vetche2D::Logger::QuickLog(float i)
{
	std::cout << "QuickLog: " << i << "\r";
}

void Vetche2D::Logger::RefreshData()
{
	m_MaxTxtDisplayTime = m_MaxTxtDisplaySeconds * (1/game->getDeltaTime());
	m_TxtDisplayTime--;
}

void Vetche2D::Logger::DrawText()
{
	if (m_TxtDisplayTime <= 0)
	{
		m_TxtDisplayTime = 0;
	}
	else
	{
		game->draw(m_DispTxt);
	}
}

void Vetche2D::Logger::AddStringToDisplay()
{
	m_DispTxt.setString(m_Log);
	m_DispTxt.setPosition(20, 0);
	m_TxtDisplayTime = m_MaxTxtDisplayTime;
}
