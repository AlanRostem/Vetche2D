#include "World.h"
#include "Entity.h"
#include <iostream>

namespace Vetche2D {
	World::World()
	{
	}

	World::~World()
	{
	}
	void World::Update()
	{
		for (unsigned int i = 0; i < (unsigned int)ent_list.size(); i++) {
			auto e = ent_list[i];
			e->Update();
			if (e->toRemove())
			{
				ClearEntity(i);
			}
		}
	}

	void World::SpawnEntity(Entity * ent)
	{
		ent_list.push_back(ent);
	}

	Entity * World::getEntity(unsigned int i)
	{
		if (i < (unsigned int)ent_list.size())
		{
			return ent_list[i];
		}
		std::cout << "Entity not found" << std::endl;
		return nullptr;
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
}