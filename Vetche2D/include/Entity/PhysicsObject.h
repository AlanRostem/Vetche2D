#pragma once
#include "Entity.h"

namespace Vetche2D {
	class PhysicsObject : public Entity
	{
	public:
		PhysicsObject(float x, float y, float Width, float Height) : Entity("PhysicsObject" , x, y) 
		{
			width = Width;
			height = Height;
		}

		~PhysicsObject();
	};
}