#include "AssetManager.h"
#include "Asset.h"

Vetche2D::AssetManager::AssetManager()
{

}

Vetche2D::AssetManager::~AssetManager()
{
}

void Vetche2D::AssetManager::CreateAsset(const std::string & name, Asset * asset)
{
	m_AssetList[name] = asset;
}

void Vetche2D::AssetManager::LoadAssetsFromScript(const std::string & file_path)
{
	//TODO: Add a file parsing method for the .assetscript files. 
}

void Vetche2D::AssetManager::AddAssetPrefixToList(const std::string & prefix)
{
	for (auto &p : m_AssetTypePrefices)
	{
		if (p != prefix)
		{
			m_AssetTypePrefices.push_back(prefix);
		}
	}
}