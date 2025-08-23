#ifndef TURN_HPP
#define TURN_HPP

#include "Player.hpp"

namespace models
{
    class Turn
    {
    public:
        Turn();

        Player getCurrentPlayer();

        Player getRivalPlayer();

        void change();

    private:
        int index;
    };
}

#endif
