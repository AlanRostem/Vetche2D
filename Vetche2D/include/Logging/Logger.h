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
	private:
		unsigned int m_CharSize = 20;
		std::string m_Log;
		sf::Font m_DefaultFont;
		sf::Text m_DispTxt;
		std::stringstream stream;
	};
}