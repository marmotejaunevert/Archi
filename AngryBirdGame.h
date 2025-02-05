#pragma once
#include "Game.h"
#include "MeshActor.h"
#include "MusicSample.h"
#include "Duck.h"
#include "Bird.h"
#include "Label.h"

using namespace UI;

class AngryBirdGame : public Game
{
	MeshActor* background;
	MusicSample* music;

	// Ball
	Bird* bird;
	MeshActor* floor;

public:
	AngryBirdGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;
};