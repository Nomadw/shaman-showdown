#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"
#include "Vector3.h"

using namespace std;
class RotationComponent : GameComponent
{
#pragma region Variables
public:
	Vector3 rotationVector;
private:

#pragma endregion

#pragma region Constructors/Destuctors
	RotationComponent();
	~RotationComponent();
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
