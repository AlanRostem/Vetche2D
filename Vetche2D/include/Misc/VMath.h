#pragma once
#include "../Core/Engine.h"

namespace Vetche2D {
	typedef unsigned short int uint16;
	typedef short int int16;

	constexpr float PI = 3.14159f;

	struct Vector2D {
		Vector2D() : x(0.0f), y(0.0f) {}
		Vector2D(float X, float Y) : x(X), y(Y) {}
		Vector2D(int X, int Y) : x(float(X)), y(float(Y)) {}
		float x;
		float y;
		float distance(Vector2D &other);
		float angle(Vector2D &other);
		float operator*(Vector2D &other);
		Vector2D operator+(Vector2D &other);
		Vector2D operator-(Vector2D &other);
	};
	
	bool intersect(Vector2D &a, Vector2D &b, Vector2D &c, Vector2D &d);
	Vector2D getPosFromIntersection(Vector2D & a, Vector2D & b, Vector2D & c, Vector2D & d);

	float rng();
	float rng(float min, float max);	
}