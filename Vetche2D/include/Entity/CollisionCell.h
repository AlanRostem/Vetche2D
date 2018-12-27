#pragma once
#include "../Core/Engine.h"
#include "../Misc/VMath.h"
#include <vector>
#include <map>

namespace Vetche2D {
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