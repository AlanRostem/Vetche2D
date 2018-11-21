#include "Logger.h"
#include <sstream>
#include <fstream>
#include "Game.h"

Vetche2D::Logger::Logger()
{

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
}

void Vetche2D::Logger::QuickLog(int i)
{
	std::cout << "QuickLog: " << i << "\r";
}

void Vetche2D::Logger::QuickLog(float i)
{
	std::cout << "QuickLog: " << i << "\r";
}
