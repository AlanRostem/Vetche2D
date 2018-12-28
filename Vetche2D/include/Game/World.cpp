#include "World.h"
#include "../Entity/Entity.h"
#include "../Entity/CollisionCell.h"
#include "../Core/Initialize.h"
#include <iostream>

namespace Vetche2D {
	World::World(int collCellSize, int tileSize)
		: m_CollisionCellSize(collCellSize), m_TileSize(tileSize),
		  m_OutOfBoundsCell(
			  new CollisionCell(float(unsigned int()), float(unsigned int()), 
						collCellSize, collCellSize))
	{

	}

	World::~World()
	{
	}

	void World::UpdateScene()
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

	void World::DrawScene()
	{
		for (auto &e : ent_list)
		{
			e->Draw();
		}
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
			return;
		}
		game->Log("Failed to clear entity from world. Index: " + i);
	}

	//May get removed
	std::vector<Entity*>& World::GetEntityList()
	{
		return ent_list;
	}
	
	CollisionCell * const & World::GetCollisionCellAt(float x, float y)
	{
		int xx = (int)x / game->COLLISION_CELL_SIZE();
		int yy = (int)y / game->COLLISION_CELL_SIZE();
		if (xx < 0 || xx > (int)m_CollisionGrid[0].size() || yy < 0 || yy >(int)m_CollisionGrid.size())
		{
			return m_OutOfBoundsCell;
		}
		return m_CollisionGrid[yy][xx];
	}

	int World::COLLISION_CELL_SIZE()
	{
		return 0;
	}

	int World::TILE_SIZE()
	{
		return m_TileSize;
	}
}