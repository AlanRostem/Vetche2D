#pragma once
#include "Engine.h"
#include "Asset.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Vetche2D {
	//Animation struct that can be created like: Animation a = {0, 1, 2, 3};
	struct Animation {
		Animation(int startColumn, int endColumn, int preferredRow, float frameSpeedSeconds)
			: start_col(startColumn), end_col(endColumn), pref_row(preferredRow), frame_speed(frameSpeedSeconds)
		{

		}
		//Initializable values
		int start_col; //Start of row
		int end_col; //End of row
		int pref_row; //Preferred row to be animated
		float frame_speed; //Frame speed in seconds

		//Non-init values
		int current_col = start_col;
		int current_row = 0;
		float passed_time = 0;
		bool stop = false;
		bool reverse = false;
	};

	//A rectangle to be used as a definitive position on the sprite sheet
	class OffsetRect
	{
	public:
		OffsetRect(float X, float Y, int W, int H)
			: offsetX(X), offsetY(Y), width(W), height(H)
		{
			rect = sf::IntRect(int(X), int(Y), width, height);
		}
		OffsetRect() {}
		~OffsetRect() {}
		float offsetX, offsetY;
		int width, height;
		sf::IntRect rect;
	};

	//Class for creating offsets in a huge sprite sheet that holds almost all the sprites to be used in our program
	class Spritemap : public Asset
	{
	public:
		Spritemap(const std::string & file_path, const std::string & name);
		~Spritemap();

		//Define a string for the name of the character/object that uses the sprite at the position with dimensions
		void BindSprite(const std::string &name, float offsetX, float offsetY, int frame_width, int frame_height);

		//Uses an animation object to animate the row of frames
		void Animate(const std::string &name, Animation &anim);

		//Draw at position
		void Draw(const std::string& name, float x, float y);

		//Draw at position and resize
		void Draw(const std::string& name, float facX, float facY, float x, float y);

		//Draw at position and rotate
		void Draw(const std::string& name, float angle, float x, float y);

		//Draw at position, rotate and resize
		void Draw(const std::string& name, float angle, float facX, float facY, float x, float y);

		//Draw at position, resize and rotate along a position (originX, originY)
		void Draw(const std::string& name, float angle, float facX, float facY, float originX, float originY, float x, float y);

		//Flip the image up-side-down
		void DrawUpsideDown(const std::string &name, bool up, float angle, float facX, float facY, float x, float y);

		//Flip the image sideways
		void DrawFlipped(const std::string &name, bool left, float angle, float facX, float facY, float x, float y);

		//Draw the entire spritesheet on the screen
		void DrawFull(float x, float y);

		//Get the frame width of the sprite name
		int getWidth(std::string name)
		{
			return cropRects[name].rect.width;
		}

		//Get the height width of the sprite name
		int getHeight(std::string name)
		{
			return cropRects[name].rect.height;
		}
	private:
		//Array that holds all the offset rectangles. The index of each rect is a string
		std::map<std::string, OffsetRect> cropRects;

		//Texture loaded on the GPU
		sf::Texture texture;

		//Sprite object
		sf::Sprite sprite;
	};
}