#pragma once

class Tile
{
public:
	Tile();
	Tile(int texture);
	~Tile();

	int getTexture();
	void setTexture(int newTex);

	bool isWalkable();
	void isWalkable(bool walkable);

	int getWidth();
	void setWidth(int newWidth);

	int getHeight();
	void setHeight(int newHeight);

	void setObjectID(int value);
	int getObjectID();

	void setItemID(int value);
	int getItemID();

	void setSuperObjectID(int value);
	int getSuperObjectID();

	void isRitualZone(bool value);
	bool isRitualZone();

private:
	int texture;
	bool walkable;
	int objectID;
	int itemID;
	int superObjectID;
	bool ritual;

	int height;
	int width;
};

