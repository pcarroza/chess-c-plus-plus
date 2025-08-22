#include "models/Turn.hpp"

namespace models
{
    Turn::Turn() : currentPlayer(Player::WHITE)
    {
    }

    Player Turn::getCurrentPlayer()
    {
        return currentPlayer;
    }

    Player Turn::getRivalPlayer()
    {
        if (currentPlayer == Player::WHITE)
        {
            return Player::BLACK;
        }
        else
        {
            return Player::WHITE;
        }
    }

    void Turn::change()
    {
        if (currentPlayer == Player::WHITE)
        {
            currentPlayer = Player::BLACK;
        }
        else
        {
            currentPlayer = Player::WHITE;
        }
    }
}
