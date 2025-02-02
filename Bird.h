#pragma once
#include "MeshActor.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Bird : public MeshActor
{
	bool canMove;
	Vector2f startPosition;
	Vector2f velocity;
	float mass;
	float gravity;
	float restitution;
	float friction;
	float groundLevel;

protected:
	AnimationComponent* animation;

public:
	Bird(const float _radius);
	Bird(const Bird& _other);
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;

protected:
	virtual void RenderMesh(RenderWindow& _window) override;

public:
	void ApplyBounce(const Vector2f& _normal);
	void AddForce(const Vector2f _velocity);

	virtual void Construct() override;
	virtual void Deconstruct() override;
};