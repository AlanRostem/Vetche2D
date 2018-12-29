#pragma once
#include "Entity.h"

namespace Vetche2D {
	class PhysicsObject : public Entity
	{
	public:
		PhysicsObject(float x, float y, int Width, int Height);
		~PhysicsObject();

		// Set the velocity of the object
		void SetVelocity(float x, float y);

		// Increment the object's position with its current velocity values
		// as a movement offset.
		void Move() override;

		// Set the default acceleration values of the object
		void SetAcceleration(float x, float y);

		// Increment the velocity of the object
		void Accelerate(float x, float y);

		// Increment the velocity of the object with its current acceleration values
		void Accelerate();

		// Set the friction values of the object
		void SetFriction(float x, float y);

		// Add a friction effect to the object. If you want to neglect friction
		// on one axis call it like so: SetFriction(0.8, 0);
		void Glide(float x, float y);

		// Add a friction effect with its current friction values
		void Glide();

		//Get the current velocity of the object
		inline Vector2D& GetVelocity() { return vel; }
		inline Vector2D& GetAcceleration() { return acc; }
		inline Vector2D& GetFriction() { return fric; }

	private:
		Vector2D vel;
		Vector2D acc;
		Vector2D fric;
		float m_MaxVelocityX;
		float m_MaxVelocityY;
	};
}