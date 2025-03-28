#pragma once
#include "../Core/Engine.h"
#include "../Misc/VMath.h"
#include <string>
#include <map>
#include <vector>
#include <functional>

namespace Vetche2D {
	//WARNING: Initialize with "new Entity(parameters)" when you want to spawn the entity.
	//Do the same with inherited classes: "new Inherited(parameters)"
	//This class gets automatially pushed into the global game object as a pointer
	//and MUST ALSO be defined as a pointer.
	class Entity
	{
	public:
		Entity();
		Entity(const char * name, float x, float y);
		~Entity();
		void Update();
		void Draw();
		bool toRemove();
		std::string getName();

		// Move the object at a certain offset (considered velocity)
		void Move(float offsetX, float offsetY);

		virtual void Move() {}

		// Set the position of the object
		void Place(float x, float y);

		// Get the object's current position
		Vector2D& GetPosition();

	protected:

		// Useful tool to organize entities that inherited from this class. 
		// Remember to call upon declaring a new class that inherits from
		// multiple other ones in case it does not call this by default in the constructor
		void SetName(const std::string & name);
		void Remove();
		
		// Function called upon constructing a character. Define a lambda function within this to implement
		// additional algorithms to be updated in other inherited classes
		void AddUpdate(std::function <void()> lambda);
		void AddDrawFunction(std::function <void()> lambda);

		// Map a string to a function that is called upon certain events. 
		// Different event types can be found on the documentation.
		void AddEventListener(const std::string & eventType, std::function<void()> lambda);
		void CallEvent(const std::string & eventType);

		// Add an operation that you want to be done with other exsisting entities
		// This is called in the game loop. If you require certain members of inherited
		// entities, make sure to do a dynamic cast to your object in order to perform
		// your wanted calculations. Casting.h is included in the main .h file.
		void AddEntityOperation(std::function<void(Entity* const &ent)> lambda);

	private:
		// Calls all entity operations that were added during abstraction.
		// These are usually collision handling and/or other operations
		// if the entity is a different kind (checked by casting)
		void EntityOperations(Entity * const & ent);

	protected:
		Vector2D pos;
		int width, height;
	private:
		bool m_toRemove = false;
		std::vector<std::string> m_InheritedNames;
		std::vector<std::function<void()>> m_AdditionalUpdates;
		std::vector<std::function<void()>> m_DrawFunctions;
		std::map<std::string, std::vector<std::function<void()>>> m_Events;
		std::vector<std::function<void(Entity* const &ent)>> m_EntityOperations;

		// Exists only to enable the polymorphic class type. This function wont be used but must exist!
		virtual void Polymorphic() {};
	};
}
