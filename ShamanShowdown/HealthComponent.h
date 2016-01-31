#pragma once
//Custom Includes
#include "GameComponent.h"

using namespace std;
class HealthComponent : public GameComponent
{
#pragma region Variables
public:
private:
	float health;
	float maxHealth;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	HealthComponent(int health);
	~HealthComponent();
#pragma endregion

#pragma region Mutators
public:
	float HealthRaw();
	float Health();
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	void render(Renderer * renderer){}
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void TakeDamage(float percentage);
private:
#pragma endregion

private:
};
