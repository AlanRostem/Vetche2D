#pragma once
#include "../Core/Engine.h"
#include <SFML/Graphics.hpp>

namespace Vetche2D {
	class gfx {
	public:
		gfx();
		~gfx();

		static void FillRect(float x, float y, int width, int height);

		static void FillColor(const sf::Color &color);
		static void FillColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
	private:
		//Static objects used in public functions

		static sf::Color s_Color;
		static sf::RectangleShape s_Rect;
	};
}