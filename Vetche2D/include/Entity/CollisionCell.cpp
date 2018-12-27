#include "CollisionCell.h"
#include "../Core/Initialize.h"

Vetche2D::CollisionCell::CollisionCell(float x, float y, int Width, int Height)
	: pos(x, y), width(Width), height(Height)
{
}

void Vetche2D::CollisionCell::AddEntity(Entity * const & ent)
{
	push_back(ent);
}

void Vetche2D::CollisionCell::RemoveEntity(Entity * const & ent)
{
	for (size_t i = 0; i < size(); i++)
	{
		if ((*this)[i] == ent)
		{
			erase(begin() + i);
			return;
		}
	}
	game->Log("Failed to remove entity from cell. Maybe the cell is empty.", this);
}

void Vetche2D::CollisionCell::Clear()
{
	clear();
}