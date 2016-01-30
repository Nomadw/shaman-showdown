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

void Map::loadMap(char* fileLocation)
{

}

void Map::draw()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); i++)
		{
			Tile* tile = &tiles[i][j];


		}
	}
}