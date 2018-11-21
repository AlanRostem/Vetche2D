#pragma once
#include "Entity.h"

namespace Vetche2D {
	class PhysicsObject : public Entity
	{
	public:
		PhysicsObject(float x, float y, float width, float height) : Entity("PhysicsObject" , x, y)
		{
			
		}

		~PhysicsObject();
	};
}