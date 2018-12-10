#pragma once
#include "../Core/Engine.h"
#include "../Misc/VMath.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

namespace Vetche2D {
	class Logger
	{
	public:
		Logger();
		~Logger();

		//Logging function that takes in a string and a pointer to print out to
		//the STL console. This log will get saved to a string that is at the end
		//of the program saved to a file. This also logs at what time which execution
		//was completed. This is meant to be called only once and not recursively such as
		//update functions in the game loop. 
		void Log(const std::string & log, void* memoryLocation);
		void Log(const std::string & log);

		//Logs to the console, but does not save it to a file.
		//This can be called multiple times and stays on one line.
		//This function is meant to be called in loops such as update fucntions. 
		void QuickLog(const std::string & log);
		void QuickLog(int i);
		void QuickLog(float i);
	protected:
		void RefreshData();
		void DrawText();
		void AddStringToDisplay();
		void SetWindowSizeValuesForView(int width, int height);
	private:
		void IncrementLineNumber();
		void ConcatenateLog(const std::string &log);

		static unsigned int m_CharSize;
		float m_TxtDisplayTime = 0.f;
		float m_MaxTxtDisplaySeconds = 10.f;
		float m_MaxTxtDisplayTime = 0.f;
		unsigned int m_MaxCharactersPerDisplay = 60;
		static unsigned int m_NumberOfLines;
		unsigned int m_MaxNumberOfLinesPerDisplay = 20;
		sf::View m_ConsoleWindow;
		std::string m_Log;
		static sf::Font m_DefaultFont;
		sf::Text m_DispTxt;
		std::string full_Log;
		std::string m_DispSTR;

		sf::Text m_FPS;
		bool countFPS = true;
		std::stringstream stream;

		struct LogInstance : public sf::Text {
			LogInstance(const std::string &str) : m_Str(str),
				sf::Text("", m_DefaultFont, m_CharSize)
			{
				setString(m_Str);
				setPosition(20, m_CharSize * m_NumberOfLines);
				setFont(m_DefaultFont);
				setFillColor(sf::Color(0, 150, 255));
			}
			~LogInstance() {}
			std::string m_Str;
			unsigned int m_Idx;
		};

		std::vector<LogInstance> m_LogInstances;
	};
}