#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

using namespace std;
class MagicComponent : public GameComponent
{
#pragma region Variables
public:
private:
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MagicComponent();
	~MagicComponent();
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
