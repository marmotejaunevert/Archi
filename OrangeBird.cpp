#include "OrangeBird.h"

OrangeBird::OrangeBird(const float _radius) : Bird(_radius)
{
}

void OrangeBird::Construct()
{
    Super::Construct();

    const float _timeBetween = 0.5f;
    const Vector2i& _spriteSize = Vector2i(54, 58);
    const vector<SpriteData>& _spritesData =
    {
        { _timeBetween, Vector2i(14, 769), _spriteSize },
        { _timeBetween, Vector2i(81, 769), _spriteSize },
        { _timeBetween, Vector2i(148, 769), _spriteSize },
        { _timeBetween, Vector2i(253, 730), Vector2i(252,225)},
    };

    const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();
}
