#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

class GameState;
class Controls;
class GameObject;
class Renderer;

enum Items { MISSLE, SLOW_DOWN, SUPER_SPEED, FREEZE, INVERT, BOMB };

using namespace std;
class ItemComponent : public GameComponent
{
#pragma region Variables
public:
	Items item;
private:
	int texture;
	float x;
	float y;
	float size;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	ItemComponent(int textureID, Items in);
	~ItemComponent();
#pragma endregion

#pragma region Mutators
public:
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void render(Renderer * renderer);
private:
#pragma endregion

private:
};
