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
	void update();
	void render();
private:
#pragma endregion

private:
};
