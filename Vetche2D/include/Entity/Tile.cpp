#include "Tile.h"

Vetche2D::Tile::Tile(float x, float y, unsigned int ID) 
	: Entity("Tile", x, y), m_ID(ID)
{

}

Vetche2D::Tile::~Tile()
{
}
