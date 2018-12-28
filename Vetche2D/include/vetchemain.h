#pragma once
#include "Core/Engine.h"
#include "Core/Initialize.h"

int main()
{
	Vetche2D::game->DefaultFont.loadFromFile("../Vetche2D/res/fonts/default.ttf");
	Vetche2D::Setup();
	Vetche2D::game->Update();
}