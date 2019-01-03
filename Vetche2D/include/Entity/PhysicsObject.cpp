#include "PhysicsObject.h"

namespace Vetche2D {

	PhysicsObject::PhysicsObject(float x, float y, int Width, int Height) 
		: Entity("PhysicsObject", x, y)
	{
		width = Width;
		height = Height;

		SetAcceleration(0, 0.3);
		SetFriction(0.97, 1);

		AddUpdate([&] {
			Accelerate();
			Move();
			Glide();
		});
	}

	PhysicsObject::~PhysicsObject()
	{

	}
	
	void PhysicsObject::SetVelocity(float x, float y)
	{
		vel.x = x;
		vel.y = y;
	}

	void PhysicsObject::Move()
	{
		pos.x += vel.x;
		pos.y += vel.y;
	}

	void PhysicsObject::SetAcceleration(float x, float y)
	{
		acc.x = x;
		acc.y = y;
	}

	void PhysicsObject::Accelerate(float x, float y)
	{
		vel.x += x;
		vel.y += y;
	}

	void PhysicsObject::Accelerate()
	{
		vel.x += acc.x;
		vel.y += acc.y;
	}

	void PhysicsObject::SetFriction(float x, float y)
	{
		fric.x = x;
		fric.y = y;
	}

	void PhysicsObject::Glide(float x, float y)
	{
		vel.x *= x;
		vel.y *= y;
	}

	void PhysicsObject::Glide()
	{
		vel.x *= fric.x;
		vel.y *= fric.y;
	}
}