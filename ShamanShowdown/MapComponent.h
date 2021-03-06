#pragma once
#include "Globals.h"
#include "Tile.h"
#include "TileCollection.h"
#include "GameComponent.h"
#include "GameObject.h"
#include "GameState.h"
#include <vector>

class GameState;

class MapComponent : public GameComponent
{
public:
	MapComponent(GameState* gameState);
	MapComponent(TileCollection tiles);
	~MapComponent();

	Tile getTile(int x, int y);
	TileCollection getTiles();

	void setTile(int x, int y, Tile value);
	void setMap(TileCollection newMap);

	void loadMap(char* fileLocation);

	void render(Renderer* renderer);
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object){}
private:
	TileCollection tiles;
	bool to_bool(string const& s);
	GameState* gameState;
};

