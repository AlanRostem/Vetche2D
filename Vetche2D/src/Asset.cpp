#include "Asset.h"

Vetche2D::Asset::Asset(const std::string & AssetTypePrefix)
	: m_AssetTypePrefix(AssetTypePrefix)
{

}

Vetche2D::Asset::~Asset()
{
}

std::string & Vetche2D::Asset::getName()
{
	return m_AssetTypePrefix + "_" + m_Name;
}
