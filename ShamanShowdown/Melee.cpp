#include "Melee.h"


MeleeComponent::MeleeComponent()
{
}


MeleeComponent::~MeleeComponent()
{
}


int MeleeComponent::GetStrength()
{
	return strength;
}

void MeleeComponent::SetStrength(int value)
{
	strength = value;
}