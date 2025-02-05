#include "BigBrother.h"

BigBrother::BigBrother(const float _radius) : Bird(_radius)
{
}

void BigBrother::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(69, 67);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(11, 581), _spriteSize },
        { _timeBetween, Vector2i(82, 582), _spriteSize },
        { _timeBetween, Vector2i(151, 582), _spriteSize },
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
