#include "Spritemap.h"
#include "../Core/Initialize.h"
#include "../Misc/VMath.h"

Vetche2D::Spritemap::Spritemap(const std::string & file_path, const std::string & name)
	: Asset("sprt"), sprite(sf::Sprite(texture))
{
	texture.loadFromFile(file_path);
	giveName(name);
}

Vetche2D::Spritemap::~Spritemap()
{

}

void Vetche2D::Spritemap::BindSprite(const std::string& name, float offsetX, float offsetY, int frame_width, int frame_height)
{
	cropRects[name] = OffsetRect(offsetX, offsetY, frame_width, frame_height);
}

void Vetche2D::Spritemap::Animate(const std::string &name, Animation &anim)
{

	if ((anim.passed_time += game->getDeltaTime()) >= anim.frame_speed)
	{
		if (anim.current_col < anim.end_col)
		{
			anim.current_col++;
		}
		else
		{
			anim.current_col = anim.start_col;
		}
		anim.passed_time = 0;
	}

	cropRects[name].rect.left = int(getWidth(name) * (anim.current_col % anim.frame_per_row));
	cropRects[name].rect.top = int(getHeight(name) * (anim.current_col / anim.frame_per_row));
}

void Vetche2D::Spritemap::Draw(const std::string&name, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect); //Crops the image to the rect
	sprite.setPosition(x, y);
	game->draw(sprite);
}

void Vetche2D::Spritemap::Draw(const std::string&name, float angle, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setPosition(x , y );
	sprite.setRotation(angle * 180 / PI); //Rotation must be converted to degrees
	game->draw(sprite);
	sprite.setRotation(0); //Resets the rotation after it's drawn each frame in the game
}

void Vetche2D::Spritemap::Draw(const std::string&name, float angle, float facX, float facY, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setPosition(x, y);
	sprite.setRotation(angle * 180 / PI);
	sprite.setScale(facX, facY);
	game->draw(sprite);
	sprite.setRotation(0);
	sprite.setScale(1, 1);
}

void Vetche2D::Spritemap::Draw(const std::string&name, float angle, float facX, float facY, float originX, float originY, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setPosition(x , y );
	sprite.setOrigin(originX, originX);
	sprite.setRotation(angle * 180 / PI);
	sprite.setScale(facX, facY);
	game->draw(sprite);
	sprite.setRotation(0);
	sprite.setOrigin(0, 0);
	sprite.setScale(1, 1);
}

void Vetche2D::Spritemap::DrawUpsideDown(const std::string&name, bool up, float angle, float facX, float facY, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setRotation(angle * 180.f / PI);
	sprite.setScale(facX, facY);
	sprite.setOrigin((float)cropRects[name].rect.width / 2.f, (float)cropRects[name].rect.height / 2.f);
	if (up)
	{
		sprite.setScale(sprite.getScale().x, -sprite.getScale().y);
	}
	sprite.setPosition(x , y );
	game->draw(sprite);
	sprite.setRotation(0);
	sprite.setScale(1, 1);
}

void Vetche2D::Spritemap::DrawFlipped(const std::string&name, bool left, float angle, float facX, float facY, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setRotation(angle * 180.f / PI);
	sprite.setScale(facX, facY);
	sprite.setOrigin((float)cropRects[name].rect.width / 2.f, (float)cropRects[name].rect.height / 2.f);
	if (left)
	{
		sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
	}
	sprite.setPosition(x , y );
	game->draw(sprite);
	sprite.setRotation(0);
	sprite.setScale(1, 1);
}

void Vetche2D::Spritemap::Draw(const std::string&name, float facX, float facY, float x, float y)
{
	sprite.setTextureRect(cropRects[name].rect);
	sprite.setPosition(x , y );
	sprite.setScale(facX, facY);
	game->draw(sprite);
	sprite.setScale(1.f, 1.f);
}

void Vetche2D::Spritemap::DrawFull(float x, float y)
{
	sprite.setPosition(x , y );
	game->draw(sprite);
}
