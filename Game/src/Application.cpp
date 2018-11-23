#include <vetche2d>
#include <iostream>

vtc::Character * e;
vtc::Character * e1;

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

void vtc::Draw()
{

}

int main()
{
	e = new vtc::Character(65.f, 55.f, 32.f, 32.f, 100.f);
	e1 = new vtc::Character(234.f, 765.f, 32.f, 32.f, 250.f);
	vtc::game->Update();
}