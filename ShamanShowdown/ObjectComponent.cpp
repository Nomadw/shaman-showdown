#include "ObjectComponent.h"
#include "Renderer.h"
#include "GameState.h"
#include "Controls.h"
#include "GameObject.h"
#include "TransformComponent.h"

ObjectComponent::ObjectComponent(int textureID)
{

}


ObjectComponent::~ObjectComponent()
{
}


void ObjectComponent::update(GameState* state, float deltaTime, Controls* controls, GameObject* object)
{
	x = object->transform->Translation().getX() - 0.5f;
	y = object->transform->Translation().getY() - 0.5f;
	size = 1.0f * 64.0f;
}

void ObjectComponent::render(Renderer * renderer)
{	
	renderer->draw(texture, x * 64, y * 64, size);
}