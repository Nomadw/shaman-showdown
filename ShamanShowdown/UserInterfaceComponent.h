#pragma once
#include "GameComponent.h"
class UserInterfaceComponent : public GameComponent
{
public:
	UserInterfaceComponent();
	~UserInterfaceComponent();

	int health1;
	int health2;
	int health3;
	int health4;

	int randcount;

	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object);
	void render(Renderer * renderer);


};

