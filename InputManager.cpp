#include "InputManager.h"

void Input::InputManager::UpdateActionMaps()
{
}

void Input::InputManager::Update(RenderWindow& _window)
{
    while (const optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            _window.close();
        }
    }
}
