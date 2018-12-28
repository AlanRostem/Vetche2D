#include "Logger.h"
#include <fstream>
#include "../Game/Game.h"
#include "../Core/Initialize.h"
#include "../Misc/Casting.h"

unsigned int Vetche2D::Logger::s_NumberOfLines = 0;
unsigned int Vetche2D::Logger::m_CharSize = 15u;
unsigned int Vetche2D::Logger::m_MaxNumberOfLinesPerDisplay = 20u;
sf::Font Vetche2D::Logger::DefaultFont;
std::deque<Vetche2D::Logger::LogInstance> Vetche2D::Logger::m_LogInstances;

Vetche2D::Logger::Logger()
	: m_DispTxt(sf::Text("", DefaultFont, m_CharSize)),
	  m_FPS(sf::Text("", DefaultFont, m_CharSize))
{


	//m_DefaultFont.loadFromFile("../Vetche2D/res/fonts/default.ttf");

	m_DispTxt.setFillColor(sf::Color(0, 150, 255));
	m_DispTxt.setFont(DefaultFont);
	m_DispTxt.setPosition(20, 0);

	m_FPS.setFillColor(sf::Color(0, 150, 255));
	m_FPS.setFont(DefaultFont);
	m_FPS.setPosition(20, 0);
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
	std::stringstream stream;
	stream << std::hex << memoryLocation;
	ConcatenateLog(log + " - memory address: " + stream.str());
}

void Vetche2D::Logger::Log(const std::string & log)
{
	ConcatenateLog(log);
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
	if (m_LogInstances.size() > m_MaxLogInstances)
	{
		for (unsigned int i = 0; i <= m_MaxLogInstances * 2 / 3; i++)
		{
			m_LogInstances.erase(m_LogInstances.begin());
		}
	}
	if (game->event.type == sf::Event::MouseWheelScrolled && m_TxtDisplayTime > 0)
	{
		for (auto &i : m_LogInstances)
		{
			i.move(0, game->event.mouseWheelScroll.delta * 5);
		}	
	}
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
		for (auto &i : m_LogInstances)
		{
			game->draw(i);
		}
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
	m_TxtDisplayTime = m_MaxTxtDisplayTime;
}

void Vetche2D::Logger::SetWindowSizeValuesForView(int width, int height)
{
	m_ConsoleWindow = sf::View(
		sf::FloatRect(0.f, 0.f, (float)width, (float)height));
	m_ConsoleWindow.setViewport(sf::FloatRect(0.f, 0.4f, 1.f, 1.f));
}

void Vetche2D::Logger::IncrementLineNumber()
{
	s_NumberOfLines++;
	int j = 0;
	for (auto &i : m_LogInstances)
	{
		j++;
		i.setPosition(i.X, i.Y - (int)m_CharSize * ((int)s_NumberOfLines - j));
	}
}

void Vetche2D::Logger::ConcatenateLog(const std::string & log)
{
	full_Log = "\n\n" + log;
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
	m_LogInstances.push_back(LogInstance(full_Log));
	//std::cout << m_LogInstances.size() << std::endl;
	m_Log += full_Log;
	AddStringToDisplay();
	full_Log = "";
}
