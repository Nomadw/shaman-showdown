#pragma once
#include "GameComponent.h"
class TeamMemberComponent :
	public GameComponent
{
public:
	TeamMemberComponent(int teamID);
	~TeamMemberComponent();
	int team;
	void render(Renderer * renderer){}
	void update(GameState * state, float deltaTime, Controls* controls, GameObject * object){}
};

