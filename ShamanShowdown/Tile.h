#pragma once

class Tile
{
public:
	Tile();
	Tile(int texture);
	~Tile();

	int getTexture();
	void setTexture(int newTex);

	bool isWalkable();
	void isWalkable(bool walkable);

	int getWidth();
	void setWidth(int newWidth);

	int getHeight();
	void setHeight(int newHeight);

private:
	int texture;
	bool walkable;

	int height;
	int width;
};

