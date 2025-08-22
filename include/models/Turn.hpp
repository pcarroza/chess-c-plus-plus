#ifndef TURN_HPP
#define TURN_HPP

#include "Color.hpp"

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
        Player currentPlayer;
    };
}

#endif
