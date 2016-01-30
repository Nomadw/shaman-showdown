#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

class TransformComponent;

using namespace std;
class InputComponent : public GameComponent
{
#pragma region Variables
public:
private:
#pragma endregion

#pragma region Constructors/Destuctors
public:
	InputComponent();
	~InputComponent();
#pragma endregion

#pragma region Variables
public:
private:
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
