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
		float getDeltaTime();

		sf::View m_Camera;
	private:
		World m_World;
		sf::Clock m_Clock;
		sf::Time m_DeltaTime;
		std::string m_WindowName = "Unnamed application";
		bool killApplication = false;
	};
}