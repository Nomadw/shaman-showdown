#pragma once
//STL Includes
#include <Windows.h>
//Custom Includes
#include "GameComponent.h"

class TransformComponent;

using namespace std;
class InputComponent : public GameComponent
{
	enum KEYS
	{
		KEYS_UP = 0,
		KEYS_LEFT = 1,
		KEYS_DOWN = 2,
		KEYS_RIGHT = 3
	};

#pragma region Variables
public:
private:
	WPARAM chars[4];
#pragma endregion

#pragma region Constructors/Destuctors
public:
	InputComponent(WPARAM up, WPARAM left, WPARAM down, WPARAM right);
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
