#pragma once
#include "Bird.h"
class OrangeBird : public Bird
{
public:
	OrangeBird(const float _radius);
public:
	virtual void Construct() override;
};