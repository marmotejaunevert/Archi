#include "WhiteBird.h"

WhiteBird::WhiteBird(const float _radius) : Bird(_radius)
{
}

void WhiteBird::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(58, 66);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(11, 363), _spriteSize },
        { _timeBetween, Vector2i(66, 363), _spriteSize },
        { _timeBetween, Vector2i(121, 363), _spriteSize },
        { _timeBetween, Vector2i(178, 366), Vector2i(61, 63)},
        { _timeBetween, Vector2i(240, 363), Vector2i(50, 75)},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
