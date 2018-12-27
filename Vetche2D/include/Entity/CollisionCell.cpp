#include "CollisionCell.h"
#include "../Core/Initialize.h"

void Vetche2D::CollisonCell::AddEntity(Entity * const & ent)
{
	push_back(ent);
	m_EntityIdentifiers[ent] = (unsigned int)size();
}

void Vetche2D::CollisonCell::RemoveEntity(Entity * const & ent)
{
	erase(begin() + m_EntityIdentifiers[ent]);
	m_EntityIdentifiers.erase(ent);
}
