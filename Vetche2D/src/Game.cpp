#include "Game.h"

Vetche2D::Game::Game()
{
	m_Window.create(sf::VideoMode(960, 640), "Codename: Rubigo", sf::Style::Close | sf::Style::Titlebar);
}

Vetche2D::Game::~Game()
{

}

sf::RenderWindow & Vetche2D::Game::getWindow()
{
	return m_Window;
}

Vetche2D::World & Vetche2D::Game::getWorld()
{
	return m_World;
}

void Vetche2D::Game::Update()
{
	while (m_Window.isOpen())
	{
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				killApplication = true;
				break;
			}
		}
		m_World.Update();
		Vetche2D::Step();
		m_Window.clear();
		ComposeFrame();
		Vetche2D::Draw();
		m_Window.display();
		if (killApplication)
		{
			m_Window.close(); 
			delete this;
			break;
		}
	}
}

void Vetche2D::Game::ComposeFrame()
{

}
