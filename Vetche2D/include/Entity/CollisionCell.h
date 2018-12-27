#pragma once
#include "../Core/Engine.h"
#include <vector>
#include <map>

namespace Vetche2D {
	class CollisonCell : private std::vector<class Entity*>
	{
	public:
		CollisonCell() {}
		~CollisonCell() {}
		
		void AddEntity(Entity * const &ent);
		void RemoveEntity(Entity * const &ent);
	};

}