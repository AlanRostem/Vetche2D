#pragma once
#include "../Core/Engine.h"
#include "World.h"
#include "../Logging/Logger.h"
#include "../Asset/AssetManager.h"
#include "../File/JSONParser.h"

#include <SFML/Graphics.hpp>

namespace Vetche2D {
	class Game : public Logger, public AssetManager, public sf::RenderWindow, public World, public JSONParser
	{
	public:
		Game();
		~Game();
		//Public getters, setters and other callables:

		void Update();
		void ComposeFrame();	
		float getDeltaTime();

		//Initializers:
		
		void SetWindow(int width, int height, const std::string& name);
		void SetTileSize(int size);
		void SetCollisionCellSize(int size);

		//Public object members:

		sf::Event event;
		sf::View m_Camera;
	private:
		//Data members 

		sf::Clock m_Clock;
		sf::Time m_DeltaTime;
		std::string m_WindowName = "Unnamed application";

		bool killApplication = false;
	};
}