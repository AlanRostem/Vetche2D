#pragma once
#include "Engine.h"
#include <vector>
#include <map>

namespace Vetche2D {
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();
		void CreateAsset(const std::string & name, class Asset* asset);
		// Loads a .assetscript file, loads all its files and then
		// creates objects based on the type prefix in the file
		// and the respective file paths.
		void LoadAssetsFromScript(const std::string & file_path);

		static void AddAssetPrefixToList(const std::string & prefix);
	private:
		std::map<std::string, class Asset*> m_AssetList;
		static std::vector<std::string> s_AssetTypePrefices;
	};
}