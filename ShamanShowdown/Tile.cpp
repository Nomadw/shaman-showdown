#include "Tile.h"

Tile::Tile()
{
	this->texture = -1;
}

Tile::Tile(int texture)
{
	this->texture = texture;
}

Tile::~Tile()
{
}

int Tile::getTexture()
{
	return texture;
}

void Tile::setTexture(int newTex)
{
	texture = newTex;
}

bool Tile::isWalkable()
{
	return walkable;
}

void Tile::isWalkable(bool walkable)
{
	this->walkable = walkable;
}