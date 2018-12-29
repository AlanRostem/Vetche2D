#pragma once
#include "PhysicsObject.h"
#include <iostream>

namespace Vetche2D {
	class Character : public PhysicsObject
	{
	public:
		Character(float x, float y, int width, int height, float maxHP);
		~Character();

		float HP();
		void Damage(float value);
		void Heal(float value);
	private:
		float m_CurrentHP;
		float m_MaxHP;
	};
}
