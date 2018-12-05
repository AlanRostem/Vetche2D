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
	return m_Name;
}

void Vetche2D::Asset::giveName(const std::string & Name)
{
	m_Name = m_AssetTypePrefix + "_" + Name;
}
