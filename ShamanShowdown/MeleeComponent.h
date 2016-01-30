#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

using namespace std;
class MeleeComponent : public GameComponent
{
#pragma region Variables
public:
private:
	int strength;
	float stabTime;
	float stabDelay;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MeleeComponent();
	~MeleeComponent();
#pragma endregion

#pragma region Mutators
public:
	void SetStrength(int value);
	int GetStrength();
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	virtual void render(Renderer * renderer);
	virtual void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
private:
#pragma endregion

private:
};
