#pragma once
//Custom Includes
#include "GameComponent.h"

using namespace std;
class HealthComponent : public GameComponent
{
#pragma region Variables
public:
	const int MAX_HEALTH = 100;
	float health;
private:
#pragma endregion

#pragma region Constructors/Destuctors
public:
	HealthComponent();
	~HealthComponent();
#pragma endregion

#pragma region Mutators
public:
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	void render(Renderer * renderer){}
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
private:
#pragma endregion

private:
};
