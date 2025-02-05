#include "Game.h"
#include "GameManager.h"
#include "DuckHuntGame.h"
#include "AngryBirdGame.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    M_GAME.Launch(new AngryBirdGame());

	return EXIT_SUCCESS;
}