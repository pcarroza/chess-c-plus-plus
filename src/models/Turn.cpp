#include "models/Turn.hpp"

namespace models
{
    Turn::Turn() : index(0)
    {
    }

    Player Turn::getCurrentPlayer()
    {
        return PLAYERS[index];
    }

    Player Turn::getRivalPlayer()
    {
        int auxIndex = index;
        int rivalPlayerIndex = (auxIndex + 1) % 2;
        return PLAYERS[rivalPlayerIndex];
    }

    void Turn::change()
    {
        index = (index + 1) % 2;
    }
}
