#ifndef TURN_HPP
#define TURN_HPP

#include "Color.hpp"

namespace models
{
    class Turn
    {
    public:
        Turn();

        Color getCurrentPlayer();

        Color getRivalPlayer();

        void change();

    private:
        Color currentPlayer;
    };
}

#endif
