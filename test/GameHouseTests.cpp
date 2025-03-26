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
    }

public:
    void StandUp()
    {
        input->jumpEvent.Connect(this, &Player::Jump);
    }

    void Sit()
    {
        input->jumpEvent.Disconnect(this);
    }

    Input* input;
};

TEST(ConnectionTest, Connect)
{
    Input input;
    Player player;
    player.input = &input;

    player.StandUp();

    input.Update();

    //MARC aqui hauria de fer alguna comprovacio perque passi o no el test
}