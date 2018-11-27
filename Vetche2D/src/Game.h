#pragma once
#include "Engine.h"
#include "World.h"
#include "Logger.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <functional>

namespace Vetche2D {
	class Game : public Logger, public AssetManager, public sf::RenderWindow
	{
	public:
		Game();
		~Game();
		World &getWorld();

		void Update();
		void ComposeFrame();
		sf::View m_Camera;
	private:
		World m_World;
		bool killApplication = false;
	};
}