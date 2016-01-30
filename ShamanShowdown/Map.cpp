#include "Map.h"
#include <fstream>
#include <string>
#include <streambuf>

using namespace std;

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
	ifstream file;
	file.open(fileLocation, fstream::in);
	string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	
	vector<vector<string>> rows;
	vector<string> tiles;

	string buffer = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ';')
		{
			tiles.push_back(buffer);
			buffer = "";
		}
		else if (str[i] == ':')
		{
			tiles.push_back(buffer);
			buffer = "";

			rows.push_back(tiles);
			tiles.clear();
		}
		else
		{
			buffer += str[i];
		}
	}

	int columnCount = rows[0].size();

	for (int i = 1; i < rows.size(); i++)
	{
		if (rows[i].size() > columnCount)
		{
			columnCount = rows[i].size();
		}
	}

	for (int i = 0; i < columnCount; i++)
	{
		TileColumn tmpCol;
		for (int j = 0; j < rows.size(); j++)
		{
			string textID;
			string walkableS;

			bool addToText = true;

			for (int k = 0; k < rows[j][i].length(); k++)
			{
				if (rows[j][i][k] == ',')
				{
					addToText = false;
				}
				else if (rows[j][i][k] != '{' && rows[j][i][k] != '}')
				{
					if (addToText)
					{
						textID += rows[j][i][k];
					}
					else
					{
						walkableS += rows[j][i][k];
					}
				}
			}

			int textureID = atoi(textID.c_str());
			bool walkable = to_bool(walkableS);

			Tile tmpTile = Tile();
			tmpTile.setTexture(textureID);
			tmpTile.isWalkable(walkable);

			tmpCol.push_back(tmpTile);
		}

		this->tiles.pushColumn(tmpCol);
	}
}

void Map::render(Renderer* renderer)
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

bool Map::to_bool(string const& s) 
{
	return s != "0";
}

