#include "TileCollection.h"

TileCollection::TileCollection()
{
}

TileCollection::~TileCollection()
{
}

void TileCollection::pushColumn(TileColumn column)
{
	this->push_back(column);
}

TileColumn* TileCollection::getColumn(int index)
{
	return &this->at(index);
}

TileColumn& TileCollection::operator[](int x)
{
	return this->at(x);
}

int TileCollection::length()
{
	return this->size();
}