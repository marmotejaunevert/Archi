#include "YellowBird.h"

YellowBird::YellowBird(const float _radius) : Bird(_radius)
{
}

void YellowBird::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(43, 40);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(7, 171), _spriteSize },
        { _timeBetween, Vector2i(52, 171), _spriteSize },
        { _timeBetween, Vector2i(97, 171), _spriteSize },
        { _timeBetween, Vector2i(145, 173), Vector2i(44,40)},
        { _timeBetween, Vector2i(191, 173), Vector2i(44,40)},
     { _timeBetween, Vector2i(240, 172), _spriteSize},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
