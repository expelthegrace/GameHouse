#pragma once

#include "Event.h"

template <typename payload_t>
class PlayerInputEvent : public EventBase<payload_t>
{
};