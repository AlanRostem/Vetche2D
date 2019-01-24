#pragma once
#include "../Core/Engine.h"
#include <vector>
#include <map>
#include <functional>

namespace Vetche2D {
	class InputMapper {
	public:
		//Used to check for user input and map a certain call to that input
		InputMapper();
		~InputMapper();
	private:
		std::map<std::string, std::vector<std::function<void()>>> m_Events;
	};
}
