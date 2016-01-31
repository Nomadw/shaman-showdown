#pragma once
#include "GameComponent.h"
class MissileUse :
	public GameComponent
{
public:
	MissileUse();
	~MissileUse();
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void render(Renderer * renderer);
};

