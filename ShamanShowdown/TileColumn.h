#pragma once
#include "Tile.h"
#include <vector>

class TileColumn : std::vector<Tile>
{
public:
	TileColumn();
	~TileColumn();

	Tile& operator[](int y);

	int size();
};

