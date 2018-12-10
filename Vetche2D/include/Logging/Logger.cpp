#include "Logger.h"
#include <fstream>
#include "../Game/Game.h"
#include "../Core/Initialize.h"
#include "../Misc/Casting.h"

Vetche2D::Logger::Logger()
	: m_DispTxt(sf::Text("", m_DefaultFont, m_CharSize)),
	  m_FPS(sf::Text("", m_DefaultFont, m_CharSize))
{
	m_DefaultFont.loadFromFile("../Vetche2D/res/fonts/default.ttf");

	m_DispTxt.setFillColor(sf::Color(0, 150, 255));
	m_DispTxt.setFont(m_DefaultFont);
	m_DispTxt.setPosition(20, 0);

	m_FPS.setFillColor(sf::Color(0, 150, 255));
	m_FPS.setFont(m_DefaultFont);
	m_FPS.setPosition(20, 0);

	m_MaxNumberOfLinesPerDisplay = 20;
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

	full_Log = "\n\n" + log + " - memory address: " + stream.str();
	IncrementLineNumber();
	IncrementLineNumber();

	if (full_Log.size() > m_MaxCharactersPerDisplay)
	{
		for (unsigned int i = m_MaxCharactersPerDisplay; i < full_Log.size(); i += m_MaxCharactersPerDisplay)
		{
			if (i > full_Log.size())
			{
				full_Log.insert(i - full_Log.size(), "\n");
				IncrementLineNumber();
				continue;
			}
			full_Log.insert(i, "\n");
			IncrementLineNumber();
		}
	}

	m_Log += full_Log;
	AddStringToDisplay();
}

void Vetche2D::Logger::Log(const std::string & log)
{
	full_Log = "\n\n" + log;
	IncrementLineNumber();
	IncrementLineNumber();
	if (full_Log.size() > m_MaxCharactersPerDisplay)
	{
		for (unsigned int i = m_MaxCharactersPerDisplay; i < full_Log.size(); i += m_MaxCharactersPerDisplay)
		{
			IncrementLineNumber();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash))
	{
		m_TxtDisplayTime = m_MaxTxtDisplayTime;
	}
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
		game->setView(m_ConsoleWindow);
		game->draw(m_DispTxt);
		game->setView(game->getDefaultView());
	}

	if (countFPS)
	{
		m_FPS.setString("FPS: " + std::to_string(int(1.f / game->getDeltaTime())));
		game->draw(m_FPS);
	}
}

void Vetche2D::Logger::AddStringToDisplay()
{
	m_DispTxt.setString(m_Log);
	m_TxtDisplayTime = m_MaxTxtDisplayTime;
}

void Vetche2D::Logger::SetWindowSizeValuesForView(int width, int height)
{
	m_ConsoleWindow = sf::View(
		sf::FloatRect(0, 0, width, height));
	m_ConsoleWindow.setViewport(sf::FloatRect(0, 0.4, 1, 1));
}

void Vetche2D::Logger::IncrementLineNumber()
{
	++m_NumberOfLines;
	if (m_NumberOfLines >= m_MaxNumberOfLinesPerDisplay-1)
	{
		m_DispTxt.move(0, -(int)m_CharSize);
	}
	//std::cout << m_NumberOfLines << std::endl;
}
