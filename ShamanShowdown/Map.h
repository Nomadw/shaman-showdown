#pragma once
#include "Tile.h"
#include "TileCollection.h"
#include <vector>

class Map
{
public:
	Map();
	Map(TileCollection tiles);
	~Map();

	Tile getTile(int x, int y);
	TileCollection getTiles();

	void setTile(int x, int y, Tile value);
	void setMap(TileCollection newMap);

	void loadMap(char* fileLocation);
private:
	TileCollection tiles;
};

