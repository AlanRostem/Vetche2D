#include "AssetManager.h"
#include "Asset.h"

std::vector<std::string> Vetche2D::AssetManager::s_AssetTypePrefices;

Vetche2D::AssetManager::AssetManager()
{

}

Vetche2D::AssetManager::~AssetManager()
{
}

void Vetche2D::AssetManager::CreateAsset(const std::string & name, Asset * asset)
{
	m_AssetList[name] = asset;
	m_AssetList[name]->giveName(name);
}

void Vetche2D::AssetManager::LoadAssetsFromScript(const std::string & file_path)
{
	//TODO: Add a file parsing method for the .assetscript files. 
}

void Vetche2D::AssetManager::AddAssetPrefixToList(const std::string & prefix)
{
	for (auto &p : s_AssetTypePrefices)
	{
		if (p != prefix)
		{
			s_AssetTypePrefices.push_back(prefix);
		}
	}
}