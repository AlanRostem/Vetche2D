#include "gfx.h"
#include "../Core/Initialize.h"


namespace Vetche2D {
	sf::Color gfx::s_Color = sf::Color(255, 255, 255, 255);
	sf::RectangleShape gfx::s_Rect = sf::RectangleShape();

	gfx::gfx()
	{
	}

	gfx::~gfx()
	{
	}
	
	void gfx::FillRect(float x, float y, int width, int height)
	{
		s_Rect.setPosition(x, y);
		s_Rect.setSize(sf::Vector2f((float)width, (float)height));
		s_Rect.setFillColor(s_Color);
		game->draw(s_Rect);
	}
	
	void gfx::FillColor(const sf::Color & color)
	{
		s_Color.r = color.r;
		s_Color.g = color.g;
		s_Color.b = color.b;
		s_Color.a = color.a;
	}
	
	void gfx::FillColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
	{
		s_Color.r = r;
		s_Color.g = g;
		s_Color.b = b;
		s_Color.a = a;
	}
}