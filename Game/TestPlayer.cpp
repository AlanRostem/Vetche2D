#include "TestPlayer.h"
#include <vetche2d.h>

float* speed = new float(4.f);

TestPlayer::TestPlayer() : vtc::Character(0, 0, 32, 32, 100)
{
	width = 32;
	height = 32;
	AddDrawFunction([&] {
		vtc::gfx::FillColor(255, 0, 0, 250);
		vtc::gfx::FillRect(pos.x, pos.y, width, height);
	});

	AddUpdate([&] {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			SetVelocity(GetVelocity().x, *speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			SetVelocity(GetVelocity().x, -*speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			SetVelocity(*speed, GetVelocity().y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			SetVelocity(-*speed, GetVelocity().y);

		if (GetPosition().y + height > vtc::game->getSize().y)
			Place(GetPosition().x, vtc::game->getSize().y - height);
	});
}

TestPlayer::~TestPlayer()
{
}
