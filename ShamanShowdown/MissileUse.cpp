#include "MissileUse.h"
#include "Controls.h"
#include "TeamMemberComponent.h"
#include "GameObject.h"

MissileUse::MissileUse()
{
}


MissileUse::~MissileUse()
{
}

void MissileUse::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	char key;
	if (((TeamMemberComponent *)object->getComponent<TeamMemberComponent>())->team == 0) {
		key = 'Q';
	}
	else {
		key = 'O';
	}
	if (controls->isKeyPressed(key)) 
	{
		requestRemoval = true;
		//add missle and kill;
	}
}

void MissileUse::render(Renderer * renderer)
{
}
