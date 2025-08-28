#ifndef COLOR_HPP
#define COLOR_HPP

#include <array>

enum class Player
{
    WHITE = 1,
    BLACK = -1,
    NONE = 0
};

static constexpr std::array<Player, 2> PLAYERS = {Player::WHITE, Player::BLACK};

inline int getPlayerValue(Player player)
{
    return static_cast<int>(player);
}

#endif
