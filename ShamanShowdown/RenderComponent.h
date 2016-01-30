#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"

using namespace std;
class RenderComponent : public GameComponent
{
#pragma region Variables
public:
	int texture;
private:
	float x;
	float y;
	float size;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	RenderComponent(int textureID);
	~RenderComponent();
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
