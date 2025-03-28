#pragma once

#include "Event.h"

namespace Gameplay
{
	enum class GameState
	{
		Collision,
		Pickup,
		Trigger
	};

	struct GameStateData
	{
		std::vector<GameState> states;
	};
}

class GameStateChangeEvent : public EventBase<Gameplay::GameStateData>
{
};