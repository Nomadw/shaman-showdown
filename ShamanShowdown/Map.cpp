#include "Map.h"



Map::Map()
{
}

Map::Map(TileCollection tiles)
{
	this->tiles = tiles;
}

Map::~Map()
{
}

Tile Map::getTile(int x, int y)
{
	return tiles[x][y];
}

TileCollection Map::getTiles()
{
	return tiles;
}

void Map::setTile(int x, int y, Tile value)
{
	tiles[x][y] = value;
}

void Map::setMap(TileCollection newMap) 
{
	tiles = newMap;
}