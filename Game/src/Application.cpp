#include <vetche2d>
#include <iostream>

vtc::Character * e;
vtc::Character * e1;

void vtc::Setup()
{
	e = new vtc::Character(0.f, 0.f, 32.f, 32.f, 100.f);
	e1 = new vtc::Character(0.f, 0.f, 32.f, 32.f, 250.f);
}

void vtc::Step()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (e != nullptr)
		{
			e->Damage(100.f);
		}
	}
}

int main()
{
	vtc::Setup();
	vtc::game->Update();
}