#include <vetche2d.h>
#include "TestPlayer.h"

vtc::Character * e;
vtc::Character * e1;
TestPlayer* tstPlr;

vtc::Spritemap * sprt;



void vtc::Setup()
{
	game->TestArrayJSON();

	e = new vtc::Character(65.f, 55.f, 32, 32, 100.f);
	game->SpawnEntity(e);

	e1 = new vtc::Character(234.f, 765.f, 32.f, 32.f, 250.f);
	game->SpawnEntity(e1);
	
	tstPlr = new TestPlayer();
	game->SpawnEntity(tstPlr);

	sprt = new vtc::Spritemap("../Game/src/vetche.png", "vetcheLogo");
	sprt->BindSprite("full", 0, 0, 1198, 380);

}

void vtc::Step()
{
	//game->QuickLog("DeltaTime: " + std::to_string(game->getDeltaTime()));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (e != NULL)
		{
			e->Damage(100.f);
		}
	}
}

void vtc::Draw()
{
	//const std::string&name, float angle, float facX, float facY, float x, float y
	sprt->Draw("full", 0, 0.5 ,0.5, 200, 200);
}

#include <vetchemain.h>