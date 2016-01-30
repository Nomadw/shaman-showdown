#pragma once
#include "GameComponent.h"
class UserInterface :
	public GameComponent
{
public:
	UserInterface();
	~UserInterface();

	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void render(Renderer * renderer);
};

