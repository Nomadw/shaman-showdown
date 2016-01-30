#include "TileColumn.h"



TileColumn::TileColumn()
{
}


TileColumn::~TileColumn()
{
}


Tile& TileColumn::operator[](int y)
{
	return this->at(y);
}

int TileColumn::length()
{
	return this->size();
}