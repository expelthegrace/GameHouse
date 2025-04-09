---- Events library manual ----

>This library is based in two primary components:
- EventBase: Event to be connected to. Callback's payload is a templated parameter.
- ConnectionHandler: Handler for each individual connection. It will auto-disconnect if the handler is destroyed to avoid dangling connections.

> Define new event:
Derive from EventBase specifying (or keeping it templated) the payload that this event will carry.

Examples:
template <typename payload_t>
class PlayerInputEvent : public EventBase<payload_t>
{
};

//InteractionData is a custom struct
class EntityInteractionEvent : public EventBase<const Gameplay::InteractionData&>
{
};

> Connect/Disconnect to event
- call its Connect() method passing as arguments the object instance and its callback/handler method
- Connect() return value has to be stored in a ConnectionHandler object.
- To disconnect just call Disconnect() method from the ConnectionHandler.
- Event will be disconected automatically if the ConnectionHandler is deleted.

Example:
ConnectionHandler<const Gameplay::InteractionData&> interactionConnection;
interactionConnection = eventTriggerSim->interactionEvent.Connect(this, &Pawn::OnEntityInteraction);


Future improvements:
- make the payload to accept more that one parameter
- instead of mapping 1:1 object instance with its callback method do it by unique ID so each object instance can have multiple callbacks connected to a single event