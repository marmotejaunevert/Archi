#include "RedBird.h"

RedBird::RedBird(const float _radius) : Bird(_radius)
{
}

void RedBird::Construct()
{
	Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(35, 35);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(8, 8), _spriteSize },
        { _timeBetween, Vector2i(43, 8), _spriteSize },
        { _timeBetween, Vector2i(76, 8), _spriteSize },
        { _timeBetween, Vector2i(109, 9), Vector2i(38,34)},
        { _timeBetween, Vector2i(145, 11), Vector2i(37, 33)},
        { _timeBetween, Vector2i(180, 9), Vector2i(36, 35)},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
