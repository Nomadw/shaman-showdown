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

private:
	int texture;
	bool walkable;
};

