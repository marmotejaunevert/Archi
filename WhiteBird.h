#pragma once
#include "Bird.h"
class WhiteBird : public Bird
{
public:
	WhiteBird(const float _radius);
public:
	virtual void Construct() override;
};

