#include "RenderComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "TransformComponent.h"

RenderComponent::RenderComponent(int textureID)
{
	texture = textureID;
}


RenderComponent::~RenderComponent()
{
}

void RenderComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	x = object->transform->Translation().getX();
	y = object->transform->Translation().getY();
	size = 1.0f * 64.0f;
}

void RenderComponent::render(Renderer * renderer)
{
	renderer->draw(texture, x * 64, y * 64, size);
}