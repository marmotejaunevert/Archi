#include "AngryBirdGame.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"

#include "BigBrother.h"
#include "GreenBird.h"
#include "WhiteBird.h"
#include "YellowBird.h"
#include "BluesBird.h"
#include "RedBird.h"
#include "BombBird.h"
#include "OrangeBird.h"
#include "TestBird.h"

#include "Level.h"
#include "HUD.h"

using namespace Camera;
using namespace UI;

AngryBirdGame::AngryBirdGame() : Game()
{
    background = nullptr;
    music = nullptr;
    floor = nullptr;
    bird = nullptr;
}


void AngryBirdGame::Start()
{
    Super::Start();

    //music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));
    MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(window.getSize()), "Background_2", JPG)));

    const Vector2f& _floorSize = Vector2f(window.getSize().x, window.getSize().y * 0.2f);
    floor = Level::SpawnActor(MeshActor(RectangleShapeData(_floorSize, "Floor_2", JPG)));
    floor->SetPosition(Vector2f(0.0f, window.getSize().y - _floorSize.y));

    const Vector2f& _wallSize = Vector2f(window.getSize().x * 0.05f, window.getSize().y * 0.6f - _floorSize.y);

    bird = Level::SpawnActor(TestBird(1000.0f));
    bird->SetOriginAtMiddle();
    bird->SetPosition(Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.3f));
    M_CAMERA.GetCurrent()->SetTarget(bird);
}

bool AngryBirdGame::Update()
{
    Super::Update();

    return IsOver();
}

void AngryBirdGame::Stop()
{
    Super::Stop();
}