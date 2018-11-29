#include "Game.h"

Vetche2D::Game::Game() : m_Camera(sf::View(sf::FloatRect(0, 0, getSize().x, getSize().y)))
{
	create(sf::VideoMode(960, 640), "Unnamed application", sf::Style::Close | sf::Style::Titlebar);

}

Vetche2D::Game::~Game()
{

}

Vetche2D::World & Vetche2D::Game::getWorld()
{
	return m_World;
}

void Vetche2D::Game::Update()
{
	while (isOpen())
	{
		sf::Event event;
		while (pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				killApplication = true;
				break;
			}
		}
		m_DeltaTime = m_Clock.restart();
		m_World.Update();
		Vetche2D::Step();
		clear();
		ComposeFrame();
		Vetche2D::Draw();
		display();
		setFramerateLimit(60);
		if (killApplication)
		{
			close(); 
			delete this;
			break;
		}
	}
}

void Vetche2D::Game::ComposeFrame()
{

}

float Vetche2D::Game::getDeltaTime()
{
	return m_DeltaTime.asSeconds();
}
