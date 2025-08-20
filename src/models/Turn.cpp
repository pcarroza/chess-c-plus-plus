#include "models/Turn.hpp"

namespace models
{
    Turn::Turn() : currentPlayer(Color::WHITE)
    {
    }

    Color Turn::getCurrentPlayer()
    {
        return currentPlayer;
    }

    Color Turn::getRivalPlayer()
    {
        if (currentPlayer == Color::WHITE)
        {
            return Color::BLACK;
        }
        else
        {
            return Color::WHITE;
        }
    }

    void Turn::change()
    {
        if (currentPlayer == Color::WHITE)
        {
            currentPlayer = Color::BLACK;
        }
        else
        {
            currentPlayer = Color::WHITE;
        }
    }
}
