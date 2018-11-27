#pragma once
#include "Engine.h"
#include "World.h"
#include "Logger.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <functional>

namespace Vetche2D {
	class Game : public Logger, public AssetManager
	{
	public:
		Game();
		~Game();
		sf::RenderWindow &getWindow();
		World &getWorld();

		void Update();
		void ComposeFrame();
	private:
		sf::RenderWindow m_Window;
		World m_World;
		bool killApplication = false;
	};

}