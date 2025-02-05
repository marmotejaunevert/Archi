#pragma once
#include "MeshActor.h"
class Egg : public MeshActor
{
	bool canMove;
	Vector2f startPosition;
	Vector2f velocity;
	float mass;
	float gravity;
	float restitution;
	float friction;
	float groundLevel;

	//AnimationComponent* animation;
};

