#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

class GameState;
class Controls;
class GameObject;
class Renderer;

using namespace std;
class ItemComponent : public ItemComponent
{
#pragma region Variables
public:
private:
	int texture;
	float x;
	float y;
	float size;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	ItemComponent(int textureID);
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
