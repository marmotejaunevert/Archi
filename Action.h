#pragma once
#include "CoreMinimal.h"

namespace Input
{
	enum ControllerButtonsType
	{
		Start,
		Select,
		Cross,
		Circle,
		Triangle,
		Square,
		L1,
		R1,
		L2,
		R2,
		LeftStick,
		RightStick,
	};

	enum ControllerAxesType
	{
		LeftStickX,
		LeftStickY,
		RightStickX,
		RightStickY,
	};

	enum ValueType
	{
		Digital, // bool
		Axis,    // float
		Axis2,   // Vector2f
	};

	typedef optional<Event> Trigger;

	struct ActionData
	{
		ValueType type;
		Trigger trigger;

	};

	class Action
	{
		string name;
		ActionData data;
		vector<int> inputs;
		function<void()> callback;
	};
}
