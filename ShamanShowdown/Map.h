#pragma once
#include "Tile.h"
#include <vector>

typedef std::vector<std::vector<Tile>> TileCollection;

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
private:
	TileCollection tiles;
};

