#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <array>

enum class Player
{
    WHITE = 1,
    BLACK = -1,
    NONE = 0
};

static constexpr std::array<Player, 2> PLAYERS = {Player::WHITE, Player::BLACK};

inline int getPlayerDirection(Player player)
{
    return static_cast<int>(player);
}

#endif
