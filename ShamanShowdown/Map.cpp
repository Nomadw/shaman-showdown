#include "Map.h"
#include <fstream>
#include <string>
#include <streambuf>
#include "GameState.h"
#include "ObjectComponent.h"
#include "ItemComponent.h"
#include "TransformComponent.h"

using namespace std;

Map::Map(GameState* gameState)
{
	this->gameState = gameState;
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
			string object;
			string item;
			string superObj;
			string area;

			int stage = 0;

			for (int k = 0; k < rows[j][i].length(); k++)
			{
				if (stage < 6)
				{
					if (rows[j][i][k] == ',')
					{
						stage++;
					}
					else if (rows[j][i][k] != '{' && rows[j][i][k] != '}')
					{
						switch (stage)
						{
						case 0:
							textID += rows[j][i][k];
							break;
						case 1:
							walkableS += rows[j][i][k];
							break;
						case 2:
							object += rows[j][i][k];
							break;
						case 3:
							item += rows[j][i][k];
							break;
						case 4:
							superObj += rows[j][i][k];
							break;
						case 5:
							area += rows[j][i][k];
							break;
						}
					}
				}
			}

			int textureID = atoi(textID.c_str());
			bool walkable = to_bool(walkableS);
			int objID = atoi(object.c_str());
			int itemID = atoi(item.c_str());
			int superObjID = atoi(item.c_str());
			bool ritualZone = to_bool(area);

			Tile tmpTile = Tile();
			tmpTile.setTexture(textureID);
			tmpTile.isWalkable(walkable);
			tmpTile.setObjectID(objID);
			tmpTile.setItemID(itemID);
			tmpTile.setSuperObjectID(superObjID);
			tmpTile.isRitualZone(ritualZone);

			//Create the GameObjects
			if (objID >= 0)
			{
				GameObject* gsObj = new GameObject();
				gsObj->attachComponent(new ObjectComponent(objID));
				gsObj->transform->Translation() = Vector3(i + 1, j + 1);
				gameState->addGameObject(gsObj);
				
			}

			if (itemID >= 0)
			{
				GameObject* gsItem = new GameObject();
				gsItem->attachComponent(new ItemComponent(itemID));
				gameState->addGameObject(gsItem);
			}

			//GameObject* gsSuper = new GameObject();
			//gsSuper->attachComponent(new ObjectComponent(superObjID));
			//gameState->addGameObject(gsSuper);


			tmpCol.push_back(tmpTile);
		}

		this->tiles.pushColumn(tmpCol);
	}
}

void Map::render(Renderer* renderer)
{
	if (renderer->currentPass == RENDER_PASS_GROUND)
	{
		for (int i = 0; i < tiles.length(); i++)
		{
			for (int j = 0; j < tiles[i].length(); j++)
			{
				Tile* tile = &tiles[i][j];

				renderer->draw(tile->getTexture() >= 0 ? tile->getTexture() : 0, (i + 0.5f) * 64.0f, (j + 0.5f) * 64.0f, 1.0f * 64.0f);
			}
		}
	}
}

bool Map::to_bool(string const& s) 
{
	return s != "0";
}

