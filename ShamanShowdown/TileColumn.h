#pragma once
#include "Tile.h"
#include <vector>

class TileColumn : public std::vector<Tile>
{
public:
	TileColumn();
	~TileColumn();

	Tile& operator[](int y);

	int length();
};

