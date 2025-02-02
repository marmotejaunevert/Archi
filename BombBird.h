#pragma once
#include "Bird.h"

class BombBird : public Bird
{
public:
	BombBird(const float _radius);
public:
	virtual void Construct() override;
};

