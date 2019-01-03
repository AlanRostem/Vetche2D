#pragma once
#include "../Entity/Entity.h"

namespace Vetche2D {
	class Tile : public Entity
	{
	public:
		Tile(float x, float y, unsigned int ID);
		~Tile();

		enum TileType {
			pass_through, solid
		};

		inline unsigned int GetTileID() { return m_ID; }
		inline TileType GetTileType() { return m_Type; }
	private:
		float m_FrictionFactor = 1.f;
		unsigned int m_ID;
		TileType m_Type = solid;
	};
}