#pragma once
#include "../Core/Engine.h"
#include <vector>

namespace Vetche2D {
	class World
	{
	public:
		World(int collCellSize, int tileSize);
		~World();
		void UpdateScene();
		void DrawScene();
		void SpawnEntity(class Entity* const &ent);
		void ClearEntity(unsigned int i);
		std::vector<class Entity*>& GetEntityList();
	private:
		std::vector<class Entity*> ent_list;

	//Collision cell
	public:
		class CollisionCell* const &GetCollisionCellAt(float x, float y);
		int COLLISION_CELL_SIZE();
	protected:
		int m_CollisionCellSize;
	private:
		//Two-dimentional array containing all the collision cells in the grid-map
		std::vector<std::vector<class CollisionCell*>> m_CollisionGrid;
		
		//Special cell to be returned by the getter if entity is out of bounds
		class CollisionCell* m_OutOfBoundsCell;

	//Tiles
	public:
		int TILE_SIZE();
	protected:
		int m_TileSize;
	};
}

