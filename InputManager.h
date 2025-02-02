#pragma once
#include "Singleton.h"
#include "ActionMap.h"

namespace Input
{
	class InputManager : public Singleton<InputManager>
	{
		set<ActionMap*> actionMaps;

	private:
		void UpdateActionMaps();

	public:
		void Update(RenderWindow& _window);
	};

}

