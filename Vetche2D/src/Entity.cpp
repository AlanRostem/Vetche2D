#include "Entity.h"
#include "Initialize.h"
#include <iostream>

namespace Vetche2D {
	Entity::Entity()
	{
		game->console.Log("Entity initialized!", this);
		game->getWorld().SpawnEntity(this); 
		SetName("Entity");
	}

	Entity::Entity(const char * name, float x, float y)
	{
		pos.x = x;
		pos.y = y;
		SetName(name);
		game->console.Log("Entity initialized!", this);
		game->getWorld().SpawnEntity(this);
	}

	Entity::~Entity()
	{
		std::cout << m_InheritedNames.back() + " cleared from memory address " << this << std::endl;
	}

	void Entity::Update()
	{
		for (auto a : m_AdditionalUpdates)
		{
			a();
		}
		for (auto e : game->getWorld().GetEntityList())
		{
			if (e != this)
			{
				EntityOperations(e);
			}
		}
	}

	void Entity::SetName(const std::string & name)
	{
		if (m_InheritedNames.size() > 0)
		{
			game->console.Log(name + " inherited from " + m_InheritedNames.back(), this);
		}
		m_InheritedNames.push_back(name);
	}

	std::string Entity::getName()
	{
		return m_Name;
	}

	bool Entity::toRemove()
	{
		return m_toRemove;
	}

	void Entity::Remove()
	{
		m_toRemove = true;
		CallEvent("onremoval");
	}

	void Entity::AddUpdate(std::function<void()> lambda)
	{
		m_AdditionalUpdates.push_back(lambda);
	}

	void Entity::AddEventListener(const std::string & eventType, std::function<void()> lambda)
	{
		m_Events[eventType].push_back(lambda);
	}

	void Entity::CallEvent(const std::string & eventType)
	{
		game->console.Log(m_InheritedNames.back() + " event '" + eventType + "' called ", this);
		for (auto e : m_Events[eventType])
		{
			e();
		}
	}

	void Entity::EntityOperations(Entity * const & ent)
	{
		for (auto op : m_EntityOperations)
		{
			op(ent);
		}
	}

	void Entity::AddEntityOperation(std::function<void(Entity*const&ent)> lambda)
	{
		m_EntityOperations.push_back(lambda);
	}
}