#include "BombBird.h"

BombBird::BombBird(const float _radius) : Bird(_radius)
{
}

void BombBird::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.5f;
	const Vector2i& _spriteSize = Vector2i(50, 63);
	const short _y = 260;
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(7, _y), _spriteSize },
		{ _timeBetween, Vector2i(59, _y), _spriteSize },
		{ _timeBetween, Vector2i(108, _y), _spriteSize },
		{ _timeBetween, Vector2i(159, _y), _spriteSize },
		{ _timeBetween, Vector2i(210, _y), _spriteSize },
		{ _timeBetween, Vector2i(261, _y), _spriteSize },
		{ _timeBetween, Vector2i(310, _y), _spriteSize },
		{ _timeBetween, Vector2i(360, _y), _spriteSize },
	};
	//const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(80, 50) };
	const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}
