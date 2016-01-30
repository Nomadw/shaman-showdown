#pragma once
#include "TileColumn.h"
#include <vector>

class TileCollection : std::vector<TileColumn>
{
public:
	TileCollection();
	~TileCollection();

	void pushColumn(TileColumn column);
	TileColumn getColumn(int index);

	TileColumn& operator[](int x);
};

