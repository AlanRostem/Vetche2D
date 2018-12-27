#include "World.h"
#include "../Entity/Entity.h"
#include "../Entity/CollisionCell.h"
#include "../Core/Initialize.h"
#include <iostream>

namespace Vetche2D {
	World::World(int tileSize)
		: COLLISION_CELL_SIZE(tileSize), 
		  m_OutOfBoundsCell(new CollisionCell(unsigned int() - 1, unsigned int() - 1, COLLISION_CELL_SIZE, COLLISION_CELL_SIZE))
	{

	}

	World::~World()
	{
	}
	void World::Update()
	{
		m_OutOfBoundsCell->Clear();
		for (unsigned int i = 0; i < (unsigned int)ent_list.size(); i++) {
			auto e = ent_list[i];
			e->Update();
			if (e->toRemove())
			{
				ClearEntity(i);
			}
		}
	}

	void World::Draw()
	{
	}

	void World::SpawnEntity(Entity * ent)
	{
		ent_list.push_back(ent);
	}

	void World::ClearEntity(unsigned int i)
	{
		if (i < (unsigned int)ent_list.size())
		{
			delete ent_list[i];
			ent_list.erase(ent_list.begin() + i);
		}
	}
	std::vector<Entity*>& World::GetEntityList()
	{
		return ent_list;
	}
	CollisionCell * const & World::GetCollisionCellAt(float x, float y)
	{
		int xx = x / game->getWorld().COLLISION_CELL_SIZE;
		int yy = y / game->getWorld().COLLISION_CELL_SIZE;
		if (xx < 0 || xx > m_CollCells[0].size() || yy < 0 || yy > m_CollCells.size())
		{
			return m_OutOfBoundsCell;
		}
		return m_CollCells[yy][xx];
	}
}