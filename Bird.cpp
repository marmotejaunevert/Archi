#include "Bird.h"
#include "TimerManager.h"
#include "AudioManager.h"

Bird::Bird(const float _radius) : MeshActor(_radius, 30, "All")
{
	canMove = false;
	startPosition = Vector2f();
	velocity = Vector2f();
	mass = 50.0f;
	gravity = 9.81f;
	restitution = 0.85f;
	friction = 0.95f;
	groundLevel = 550.0f;

	lifeSpan = 5.0f;

	SetOriginAtMiddle();

    animation = CreateComponent<AnimationComponent>();
}

Bird::Bird(const Bird& _other) : MeshActor(_other)
{
    animation = CreateComponent<AnimationComponent>();
}

void Bird::Construct()
{
	Super::Construct();
}

void Bird::Deconstruct()
{
    Super::Deconstruct();
    animation->StopAnimation();
}

void Bird::BeginPlay()
{
    Super::BeginPlay();

    startPosition = GetPosition();
    new Timer([&]()
        {
            canMove = true;
            AddForce(Vector2f(300.0f, 0.0f));

        }, seconds(1.5f), true);
}

void Bird::Tick(const float _deltaTime)
{
    Super::Tick(_deltaTime);

    if (!canMove) return;

    // Mettre à jour la position
    const Vector2f& _displacement = velocity * _deltaTime;
    

    Move(_displacement);
}


void Bird::RenderMesh(RenderWindow& _window)
{
    Super::RenderMesh(_window);

}

void Bird::ApplyBounce(const Vector2f& _normal)
{
    // Pour ressortir du sol
    //Move(-_normal * 0.1f);

    // Appliquer le rebond : inverser la composante normale de la vitesse
    velocity -= 2.0f * DotProduct(velocity, _normal) * _normal;

    // Réduire la vitesse en fonction du facteur de restitution
    velocity *= restitution;

    // Appliquer la friction à la composante tangentielle
    velocity.x *= friction;

    // Éviter de petites oscillations en annulant de faibles valeurs
    if (abs(velocity.x) < 1.0f)
    {
        velocity.x = 0.0f;
    }

    if (abs(velocity.y) < 1.0f)
    {
        velocity.y = 0.0f;
    }
}

void Bird::AddForce(const Vector2f _velocity)
{
    velocity += _velocity;
}