#include "src/EntityInteractionEvent.h"
#include "src/GameStateChangeEvent.h"
#include "src/PlayerInputEvent.h"

#include <iostream>

class EventTriggerSimulator
{
public:
    void TriggerEvents()
    {
        //if jump button pressed
        jumpEvent.Emit(33);
        gameStateEvent.Emit(Gameplay::GameStateData());

        Gameplay::InteractionData interactionData;
        interactionEvent.Emit(interactionData);
    }

public:
    PlayerInputEvent<int> jumpEvent;
    GameStateChangeEvent gameStateEvent;
    EntityInteractionEvent interactionEvent;
};

class Pawn
{

private:
    void Jump(int meters)
    {
        inputEventCallbackTriggered = true;
    }

    void OnGameStateChanged(Gameplay::GameStateData stateData)
    {
        gameStateCallbackTriggered = true;
    }

    void OnEntityInteraction(const Gameplay::InteractionData& interactionData)
    {
        entityInteractionCallbackTriggered = true;
    }

public:
    void Activate()
    {
        jumpConnection = eventTriggerSim->jumpEvent.Connect(this, &Pawn::Jump);
        gameStateConnection = eventTriggerSim->gameStateEvent.Connect(this, &Pawn::OnGameStateChanged);
        interactionConnection = eventTriggerSim->interactionEvent.Connect(this, &Pawn::OnEntityInteraction);
    }

    void Sleep()
    {
        jumpConnection.Disconnect();
        gameStateConnection.Disconnect();
        interactionConnection.Disconnect();
    }

public:
    bool inputEventCallbackTriggered = false;
    bool gameStateCallbackTriggered = false;
    bool entityInteractionCallbackTriggered = false;

    EventTriggerSimulator* eventTriggerSim = nullptr;

private:
    ConnectionHandler<int> jumpConnection;
    ConnectionHandler<Gameplay::GameStateData> gameStateConnection;
    ConnectionHandler<const Gameplay::InteractionData&> interactionConnection;
};
