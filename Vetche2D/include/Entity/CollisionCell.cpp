#include "CollisionCell.h"
#include "../Core/Initialize.h"

void Vetche2D::CollisonCell::AddEntity(Entity * const & ent)
{
	push_back(ent);
}

void Vetche2D::CollisonCell::RemoveEntity(Entity * const & ent)
{
	for (size_t i = 0; i < size(); i++)
	{
		if ((*this)[i] == ent)
		{
			erase(begin() + i);
			return;
		}
	}
	game->Log("Failed to remove entity from cell!", this);
}
