#pragma once
#include "../Core/Engine.h"
#include "World.h"
#include "../Logging/Logger.h"
#include "../Asset/AssetManager.h"
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