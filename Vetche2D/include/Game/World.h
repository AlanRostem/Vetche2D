#pragma once
#include "../Core/Engine.h"
#include <vector>

namespace Vetche2D {
	class World
	{
	public:
		World(int tileSize);
		~World();
		void Update();
		void Draw();
		void SpawnEntity(class Entity* ent);
		void ClearEntity(unsigned int i);
		std::vector<class Entity*>& GetEntityList();
	private:
		std::vector<class Entity*> ent_list;

	//Collision cell
	public:
		class CollisionCell* const &GetCollisionCellAt(float x, float y);
		const int COLLISION_CELL_SIZE;
	private:
		std::vector<std::vector<class CollisionCell*>> m_CollCells;
		class CollisionCell* m_OutOfBoundsCell;
	};
}

