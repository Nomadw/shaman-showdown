#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

using namespace std;
class ScaleComponent : GameComponent
{
#pragma region Variables
public:

private:

#pragma endregion

#pragma region Constructors/Destuctors
	ScaleComponent();
	~ScaleComponent();
#pragma endregion

#pragma region Mutators
public:

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

