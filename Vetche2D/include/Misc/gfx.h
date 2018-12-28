#pragma once
#include "../Core/Engine.h"
#include <SFML/Graphics.hpp>

namespace Vetche2D {

	// Static class used as a namespace for drawing objects to the screen quickly.
	// Functions in this class must be called in Vetche2D::Draw or other Vetche2D
	// objects in order to work. 
	class gfx {
	public:
		gfx();
		~gfx();

		// Draws a rectangle on the screen. Works only when called in Vetche2D::Draw
		// or other Vetche2D objects.
		static void FillRect(float x, float y, int width, int height);

		static void FillColor(const sf::Color &color);
		static void FillColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
	private:
		//Static objects used in public functions

		static sf::Color s_Color;
		static sf::RectangleShape s_Rect;
	};
}