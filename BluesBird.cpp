#include "BluesBird.h"

BluesBird::BluesBird(const float _radius) : Bird(_radius)
{
}

void BluesBird::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(25, 24);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(9, 89), _spriteSize },
        { _timeBetween, Vector2i(36, 90), _spriteSize },
        { _timeBetween, Vector2i(62, 90), Vector2i(25, 24) },
        { _timeBetween, Vector2i(87, 89), Vector2i(25, 24)},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
