#pragma once
#include "Tile.h"
#include <vector>

typedef std::vector<Tile> TileColumn;

class TileCollection : std::vector<TileColumn>
{
public:
	TileCollection();
	~TileCollection();

	void pushColumn(TileColumn column);
	TileColumn getColumn(int index);
};

