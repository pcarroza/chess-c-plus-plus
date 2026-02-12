#include "models/modules/game/Turn.hpp"
#include "models/modules/game/Player.hpp"

using models::modules::game::Player;
using models::modules::game::PLAYERS;

namespace models::modules::game
{
    Turn::Turn() : index(0)
    {
    }

    Player Turn::getCurrentPlayer()
    {
        return player.fromValue(index);
    }

    Player Turn::getRivalPlayer()
    {
        int auxIndex = index;
        int rivalPlayerIndex = (auxIndex + 1) % 2;
        return player.fromValue(rivalPlayerIndex);
    }

    void Turn::change()
    {
        index = (index + 1) % 2;
    }
}
