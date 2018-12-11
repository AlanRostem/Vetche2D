#include "Game.h"

Vetche2D::Game::Game() : 
	m_Camera(sf::View(sf::FloatRect(0, 0, (float)getSize().x, (float)getSize().y)))
{
	create(sf::VideoMode(960, 640), "Unnamed application", sf::Style::Close | sf::Style::Titlebar);
	SetWindowSizeValuesForView(getSize().x, getSize().y);
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
		RefreshData();

		clear();
		Vetche2D::Draw();
		ComposeFrame();
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
	DrawText();
}

float Vetche2D::Game::getDeltaTime()
{
	return m_DeltaTime.asSeconds();
}
