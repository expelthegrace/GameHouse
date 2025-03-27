#include "src/Event.h"

#include <gtest/gtest.h>


class Input
{
public:
    void Update()
    {
        //if jump button pressed
        jumpEvent.Emit(33);
    }

public:
    EventBase<int> jumpEvent;
};

class Player
{

private:
    void Jump(int meters)
    {
        std::cout << "jumped in meters: " << meters << std::endl;
        hasJumped = true;
    }

public:
    void StandUp()
    {
        jumpConnection = input->jumpEvent.Connect(this, &Player::Jump);
    }

    void Sit()
    {
        input->jumpEvent.Disconnect(this);
    }

public:
    bool hasJumped = false;
    Input* input = nullptr;

private:
    ConnectionHandler<int> jumpConnection;
};

TEST(ConnectionTest, Connect)
{
    Input input;
    Player player;
    player.input = &input;

    player.StandUp();

    input.Update();

    EXPECT_EQ(player.hasJumped, true);
}

TEST(ConnectionTest, Disconnect)
{
    Input input;
    Player player;
    player.input = &input;

    player.StandUp();
    player.Sit();

    input.Update();

    EXPECT_EQ(player.hasJumped, false);
}

TEST(ConnectionTest, Autodisconnection)
{
    Input input;
    Player* newPlayer = new Player();
    newPlayer->input = &input;

    newPlayer->StandUp();
    delete newPlayer;
    newPlayer = nullptr;

    ASSERT_NO_THROW(input.Update(););
}