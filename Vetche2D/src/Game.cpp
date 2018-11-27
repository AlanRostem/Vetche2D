#include "Game.h"

Vetche2D::Game::Game()
{
	create(sf::VideoMode(960, 640), "Codename: Rubigo", sf::Style::Close | sf::Style::Titlebar);
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
		m_World.Update();
		Vetche2D::Step();
		clear();
		ComposeFrame();
		Vetche2D::Draw();
		display();
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
