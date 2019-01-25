#include "TestPlayer.h"
#include <vetche2d.h>

float* speed = new float(4.f);
float* acceleration = new float(.2f);

vtc::Spritemap* sprite = new vtc::Spritemap("../Game/src/bally128x128.png", "bally");
vtc::Animation plrAnim = vtc::Animation(0, 7, 4, .1f);

TestPlayer::TestPlayer() : vtc::Character(0, 0, 32, 32, 100)
{
	width = 128;
	height = 128;
	sprite->BindSprite("bally", 0, 0, 128, 128);
	AddDrawFunction([&] {
		sprite->Animate("bally", plrAnim);
		sprite->Draw("bally", pos.x, pos.y);
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
