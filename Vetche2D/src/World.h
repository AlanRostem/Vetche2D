#pragma once
#include "Engine.h"
#include <vector>

namespace Vetche2D {
	class World
	{
	public:
		World();
		~World();
		void Update();
		void SpawnEntity(class Entity* ent);
		void ClearEntity(unsigned int i);
		std::vector<class Entity*>& GetEntityList();
	private:
		std::vector<class Entity*> ent_list;
	};
}

