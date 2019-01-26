#include "TestPlayer.h"
#include <vetche2d.h>

float* speed = new float(4.f);
float* acceleration = new float(.2f);

TestPlayer::TestPlayer() : vtc::Character(0, 0, 32, 32, 100)
{
	AddDrawFunction([&] {
		vtc::gfx::FillColor(255, 0, 0, 250);
		vtc::gfx::FillRect(pos.x, pos.y, width, height);
	});

	AddUpdate([&] {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			SetVelocity(GetVelocity().x, -*speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			Accelerate(*acceleration, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			Accelerate(-*acceleration, 0);

		if (GetPosition().y + (float)height > vtc::game->getSize().y)
			Place(GetPosition().x, vtc::game->getSize().y - (float)height);
	});
}

TestPlayer::~TestPlayer()
{
}
