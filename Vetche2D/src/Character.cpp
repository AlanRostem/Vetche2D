#include "Character.h"
#include "Initialize.h"
#include "Casting.h"

Vetche2D::Character::Character(float x, float y, float width, float height, float maxHP)
	: PhysicsObject(x, y, width, height), m_MaxHP(maxHP), m_CurrentHP(maxHP)
{
	SetName("Character");
	AddUpdate([&] {
		if (m_CurrentHP == 0.0f)
		{
			Remove();
			CallEvent("ondead");
		}
	});

	AddEntityOperation([&](Entity* const &e) {
		if (IsType<Entity, Character>(e))
		{
			Character* c = CastTo<Entity, Character>(e);
			game->QuickLog(c->HP());
		}
	});
}

Vetche2D::Character::~Character()
{
}

float Vetche2D::Character::HP()
{
	return m_CurrentHP;
}

void Vetche2D::Character::Damage(float value)
{
	if (m_CurrentHP > 0.0f)
	{
		m_CurrentHP -= value;
		CallEvent("ondamage");
	}
}

void Vetche2D::Character::Heal(float value)
{
	if (m_CurrentHP < m_MaxHP)
	{
		m_CurrentHP += value;
		CallEvent("onheal");
	}
}