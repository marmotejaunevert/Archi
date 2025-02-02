#include "Game.h"
#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"

//using namespace Input;
using namespace Camera;

Game::Game()
{
	window = RenderWindow();
}


void Game::Start()
{
    window.create(VideoMode({ 800, 400 }), "Angry Birds");

    M_CAMERA.CreateCamera("DefaultCamera"); 
    //M_CAMERA.CreateCamera(Vector2f(), Vector2f(300.0f, 300.0f), "DefaultCamera");
    M_ACTOR.BeginPlay();
};

bool Game::Update()
{
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();

    //M_INPUT.Update(window);
    class InputManager : public Singleton<InputManager>
{
public:
	void Update(RenderWindow& _window);
};

    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_ACTOR.Tick(_deltaTime);

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();
    M_CAMERA.RenderAllCameras(window);
    window.display();
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}