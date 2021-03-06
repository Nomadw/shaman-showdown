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
	int team;
private:
	int texture;
	float spellSpeed;
	Vector3* direction;
	Vector3* position;
	bool move = true;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MagicProjectileComponent(int textureID, float spellSpeed, TransformComponent* target, TransformComponent* start, int teamIn);
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
	GameObject* checkCollision(GameState* state, Vector3* position);
#pragma endregion

};