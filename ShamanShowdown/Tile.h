#pragma once

class Tile
{
public:
	Tile();
	Tile(int texture);
	~Tile();

	int getTexture();
	void setTexture(int newTex);

private:
	int texture;
};

