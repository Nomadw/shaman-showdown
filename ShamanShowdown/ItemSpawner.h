#pragma once
#include "GameComponent.h"
class ItemSpawner :
	public GameComponent
{
public:
	ItemSpawner(float delayIn);
	~ItemSpawner();
	float delay;
	float timeOut;
	void render(Renderer * renderer);
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
};

