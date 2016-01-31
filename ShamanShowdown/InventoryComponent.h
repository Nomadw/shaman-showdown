#pragma once
//STL Includes
#include <stack>
#include <queue>
//Custom Includes
#include "GameComponent.h"
#include "ItemComponent.h"

using namespace std;
class InventoryComponent : public GameComponent
{
#pragma region Variables
public:

	queue<Items> inventory;
private:
#pragma endregion

#pragma region Constructors/Destuctors
public:
	InventoryComponent();
	~InventoryComponent();
#pragma endregion

#pragma region Mutators
public:
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	void render(Renderer * renderer) {}
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);

	void useItem(GameState* state, int team, GameObject* object);
	void giveItem(Items item);
private:
#pragma endregion

private:
};
