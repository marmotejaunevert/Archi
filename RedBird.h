#pragma once
#include "Bird.h"

class RedBird : public Bird
{
public:
	RedBird(const float _radius);
public:
	virtual void Construct() override;
};

