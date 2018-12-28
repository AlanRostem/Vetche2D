#pragma once
#include "../Core/Engine.h"
#include "../Misc/VMath.h"
#include <vector>
#include <map>

namespace Vetche2D {
	// Array containing pointers to entities used for reference. Entities will have an array containing these
	// upon close proximity or overlap in the world. The entity will then loop through this class' entities
	// and perform certain operations like collision on them. This way entities only use for-loops for
	// other entities within its necessary proximity.
	class CollisionCell : private std::vector<class Entity*>
	{
	public:
		CollisionCell(float x, float y, int width, int height);
		~CollisionCell() {}
		
		void AddEntity(Entity * const &ent);
		void RemoveEntity(Entity * const &ent);
		void Clear();
		Vector2D pos;
		int width, height;
	};

}