#include "TestingClasses.cpp"

#include <gtest/gtest.h>


TEST(ConnectionTests, Connect)
{
    EventTriggerSimulator eventTriggerSim;
    Pawn pawn;
    pawn.eventTriggerSim = &eventTriggerSim;

    pawn.Activate();

    eventTriggerSim.TriggerEvents();

    EXPECT_EQ(pawn.inputEventCallbackTriggered, true);
    EXPECT_EQ(pawn.gameStateCallbackTriggered, true);
    EXPECT_EQ(pawn.entityInteractionCallbackTriggered, true);
}

TEST(ConnectionTests, Disconnect)
{
    EventTriggerSimulator eventTriggerSim;
    Pawn pawn;
    pawn.eventTriggerSim = &eventTriggerSim;

    pawn.Activate();
    pawn.Sleep();

    eventTriggerSim.TriggerEvents();

    EXPECT_EQ(pawn.inputEventCallbackTriggered, false);
    EXPECT_EQ(pawn.gameStateCallbackTriggered, false);
    EXPECT_EQ(pawn.entityInteractionCallbackTriggered, false);
}

TEST(ConnectionTests, Autodisconnection)
{
    EventTriggerSimulator eventTriggerSim;
    Pawn* pawn = new Pawn();
    pawn->eventTriggerSim = &eventTriggerSim;

    pawn->Activate();
    delete pawn;
    pawn = nullptr;

    ASSERT_NO_THROW(eventTriggerSim.TriggerEvents(););

}