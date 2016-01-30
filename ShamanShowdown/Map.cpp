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
	Tile tmpTile = Tile();
	tmpTile.setTexture(0);

	for (int i = 0; i < 20; i++)
	{
		tiles.pushColumn(TileColumn());
		for (int j = 0; j < 10; j++)
		{
			tiles.getColumn(i)->push_back(tmpTile);
		}
	}
}

void Map::draw(Renderer* renderer)
{
	for (int i = 0; i < tiles.length(); i++)
	{
		for (int j = 0; j < tiles[i].length(); j++)
		{
			Tile* tile = &tiles[i][j];

			renderer->draw(tile->getTexture() >= 0 ? tile->getTexture() : 0, i * 64.0f, j * 64.0f, 1.0f * 64.0f);
		}
	}
}