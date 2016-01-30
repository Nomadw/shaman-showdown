#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"
class GameState;
class Controls;
class GameObject;
class Renderer;

using namespace std;
class MagicProjectileComponent : public GameComponent
{
	enum SPELL_DIRECTION
	{
		SPELL_DIRECTION_UP,
		SPELL_DIRECTION_DOWN,
		SPELL_DIRECTION_LEFT,
		SPELL_DIRECTION_RIGHT
	};

#pragma region Variables
public:
private:
	int texture;
	SPELL_DIRECTION direction;
	float spellSpeed;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MagicProjectileComponent(int textureID, SPELL_DIRECTION direction, float spellSpeed);
	~MagicProjectileComponent();
#pragma endregion

#pragma region Mutators
public:
private:
#pragma endregion

#pragma region Functions
public:


	//Overriders for the abstract base GameComponent
	void update(GameState* state, float deltaTime, Controls* controls, GameObject* object);
	void render(Renderer * renderer);
private:
#pragma endregion

private:
};