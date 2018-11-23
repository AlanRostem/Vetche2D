#pragma once
#include "Engine.h"
#include <string>

namespace Vetche2D { 
	// Base class for the assets in our engine. The type prefix for its name 
	// is only to be defined in an abstraction and is constant. To give the
	// asset a name use it in an initialzer list from its abstraciton. 
	class Asset
	{
	public:
		Asset(const std::string &AssetTypePrefix);
		~Asset();
		std::string &getName();
	protected:
		std::string m_Name;
	private:
		std::string m_AssetTypePrefix;
	};
}