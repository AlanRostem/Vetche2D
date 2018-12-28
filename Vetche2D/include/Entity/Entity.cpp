#include "Entity.h"
#include "../Core/Initialize.h"
#include <iostream>

namespace Vetche2D {
	Entity::Entity()
	{
		//game->SpawnEntity(this); 
		SetName("Entity");
	}

	Entity::Entity(const char * name, float x, float y)
	{
		pos.x = x;
		pos.y = y;
		SetName(name);
		//game->SpawnEntity(this);
	}

	Entity::~Entity()
	{
		game->Log(m_InheritedNames.back() + " cleared from memory address ", this);
	}

	void Entity::Update()
	{
		for (auto &a : m_AdditionalUpdates)
		{
			a();
		}

		//Temporary implementation
		for (auto &e : game->GetEntityList())
		{
			if (e != this)
			{
				EntityOperations(e);
			}
		}
	}

	void Entity::Draw()
	{
		for (auto &f : m_DrawFunctions)
		{
			f();
		}
	}

	void Entity::SetName(const std::string & name)
	{
		m_InheritedNames.push_back(name);
	}

	std::string Entity::getName()
	{
		if (m_InheritedNames.size() > 0)
		{
			return m_InheritedNames.back();
		}
		return "Empty";
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

	void Entity::AddDrawFunction(std::function<void()> lambda)
	{
		m_DrawFunctions.push_back(lambda);
	}

	void Entity::AddEventListener(const std::string & eventType, std::function<void()> lambda)
	{
		m_Events[eventType].push_back(lambda);
	}

	void Entity::CallEvent(const std::string & eventType)
	{
		game->Log(m_InheritedNames.back() + " event '" + eventType + 
		"' called at position " + 
			std::to_string(int(pos.x)) + "," + 
			std::to_string(int(pos.y)), this);
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