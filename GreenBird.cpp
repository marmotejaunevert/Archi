#include "GreenBird.h"

GreenBird::GreenBird(const float _radius) : Bird(_radius)
{
}

void GreenBird::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(68, 45);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(12, 488), _spriteSize },
        { _timeBetween, Vector2i(82, 488), _spriteSize },
        { _timeBetween, Vector2i(149, 489), _spriteSize },
        { _timeBetween, Vector2i(217, 481), Vector2i(60, 66)},
        { _timeBetween, Vector2i(282, 492), Vector2i(69, 47)},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
