#ifndef TURN_HPP
#define TURN_HPP

#include "Player.hpp"

using models::modules::game::Player;

namespace models::modules::game
{
    class Turn
    {
    public:
        Turn();

        Player getCurrentPlayer();

        Player getRivalPlayer();

        void change();

    private:
        Player player;

        int index;
    };
}

#endif
