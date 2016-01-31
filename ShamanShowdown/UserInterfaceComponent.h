#pragma once
#include "GameComponent.h"

#include <vector>
using namespace std;
class UserInterface :
	public GameComponent
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

	vector <int> health;
	vector <int> tile;


};

