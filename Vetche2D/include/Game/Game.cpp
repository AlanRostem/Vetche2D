#include "Game.h"

Vetche2D::Game::Game() : 
	m_Camera(sf::View(sf::FloatRect(0, 0, (float)getSize().x, (float)getSize().y))),
	World(32*3, 32)
{
	create(sf::VideoMode(960, 640), "Unnamed application", sf::Style::Close | sf::Style::Titlebar);
	SetWindowSizeValuesForView(getSize().x, getSize().y);
}

Vetche2D::Game::~Game()
{

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

		//Update world:
		m_DeltaTime = m_Clock.restart();
		UpdateScene(); //World function
		Vetche2D::Step(); //Global definable
		RefreshData(); //Logger function

		//Rendering:
		clear(); //Window function
		Vetche2D::Draw(); //Global definable
		ComposeFrame(); //Game function
		display(); //Window function

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

void Vetche2D::Game::SetWindow(int width, int height, const std::string& name)
{
	create(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Titlebar);
}

void Vetche2D::Game::SetTileSize(int size)
{
	m_TileSize = size;
}

void Vetche2D::Game::SetCollisionCellSize(int size)
{
	m_CollisionCellSize = size;
}
