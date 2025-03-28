#pragma once

#include "Event.h"


namespace Gameplay
{
	enum class InteractionType
	{
		Collision,
		Pickup,
		Trigger
	};

	struct InteractionData
	{
		//std::vector<std::shared_ptr<Entity>> interactionAgents;
		InteractionType type;
	};
}

class EntityInteractionEvent : public EventBase<Gameplay::InteractionData>
{
};