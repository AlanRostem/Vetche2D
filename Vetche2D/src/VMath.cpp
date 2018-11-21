#include "VMath.h"
#include <iostream>

float Vetche2D::Vector2D::distance(Vector2D & other)
{
	float xx = x - other.x;
	float yy = y - other.y;
	return sqrtf(xx*xx + yy * yy);
}

float Vetche2D::Vector2D::angle(Vector2D & other)
{
	float xx = x - other.x;
	float yy = y - other.y;
	return atan2f(yy, xx);
}

Vetche2D::Vector2D Vetche2D::Vector2D::operator+(Vector2D & other)
{
	x += other.x;
	y += other.y;
	return Vector2D(x, y);
}

Vetche2D::Vector2D Vetche2D::Vector2D::operator-(Vector2D & other)
{
	x -= other.x;
	y -= other.y;
	return Vector2D(x, y);
}

float Vetche2D::Vector2D::operator*(Vector2D & other)
{
	return (x * other.x + y * other.y);
}

bool Vetche2D::intersect(Vector2D & a, Vector2D & b, Vector2D & c, Vector2D & d)
{
	Vector2D r(b.x - a.x, b.y - a.y);
	Vector2D s(d.x - c.x, d.y - c.y);

	double dd = r.x * s.y - r.y * s.x;
	double u = ((c.x - a.x) * r.y - (c.y - a.y) * r.x) / dd;
	double t = ((c.x - a.x) * s.y - (c.y - a.y) * s.x) / dd;
	return (0 < u && u < 1 && 0 < t && t < 1);
}

Vetche2D::Vector2D Vetche2D::getPosFromIntersection(Vector2D & a, Vector2D & b, Vector2D & c, Vector2D & d)
{
	Vector2D r(b.x - a.x, b.y - a.y);
	Vector2D s(d.x - c.x, d.y - c.y);

	float dd = r.x * s.y - r.y * s.x;
	float u = ((c.x - a.x) * r.y - (c.y - a.y) * r.x) / dd;
	float t = ((c.x - a.x) * s.y - (c.y - a.y) * s.x) / dd;
	return Vector2D(a.x + t * r.x, a.y + t * r.y);
}

float Vetche2D::rng()
{
	return float(rand()) / float(32767);
}

float Vetche2D::rng(float min, float max)
{
	return rng() * (max - min) + min;
}
