#pragma once
#include "GameComponent.h"
class UserInterface :
	public GameComponent
{
public:
	UserInterface();
	~UserInterface();

	int health1;
	int health2;
	int health3;
	int health4;

	int randcount;

	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void render(Renderer * renderer);


};

