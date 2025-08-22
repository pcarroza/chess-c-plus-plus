#ifndef COLOR_HPP
#define COLOR_HPP

enum class Player
{
    WHITE = 1,
    BLACK = -1,
    NONE = 0
};

inline int getPlayerValue(Player player)
{
    return static_cast<int>(player);
}

#endif
