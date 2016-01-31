#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"
class GameState;
class Controls;
class GameObject;
class Renderer;
class TransformComponent;
class Vector3;

using namespace std;
class MagicProjectileComponent : public GameComponent
{

#pragma region Variables
public:
	enum SPELL_DIRECTION
	{
		SPELL_DIRECTION_UP,
		SPELL_DIRECTION_DOWN,
		SPELL_DIRECTION_LEFT,
		SPELL_DIRECTION_RIGHT
	};
private:
	int texture;
	SPELL_DIRECTION direction;
	float spellSpeed;
	TransformComponent* transform;
	Vector3* dirVec;
	bool should = true;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MagicProjectileComponent(int textureID, SPELL_DIRECTION direction, float spellSpeed, TransformComponent* transform);
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