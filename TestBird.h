#pragma once
#include "Bird.h"
class TestBird : public Bird
{
public:
	TestBird(const float _radius);
public:
	virtual void Construct() override;
};
