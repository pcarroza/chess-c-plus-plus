#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <array>
#include <string>
#include <cstddef>

namespace models::modules::game
{
    class Player
    {
    public:
        // Constructor de copia y asignación
        Player(const Player &) = default;
        Player &operator=(const Player &) = default;
        ~Player() = default;

        // Getters (inline constexpr para optimización)
        constexpr int getValue() const noexcept { return value_; }

        constexpr int getVectorPlayer() const noexcept { return value_; }

        const char *getName() const noexcept { return name_; }

        // Operadores de comparación (inline constexpr)

        // Métodos de verificación (inline constexpr)
        constexpr bool isValid() const noexcept
        {
            return *this != NONE;
        }

        constexpr bool isWhite() const noexcept
        {
            return *this == WHITE;
        }

        constexpr bool isBlack() const noexcept
        {
            return *this == BLACK;
        }

        const Player &getOpponent() const;

        static const Player &fromValue(int value);

        constexpr bool operator==(const Player &other) const noexcept
        {
            return value_ == other.value_;
        }

        constexpr bool operator!=(const Player &other) const noexcept
        {
            return value_ != other.value_;
        }

        constexpr bool operator<(const Player &other) const noexcept
        {
            return value_ < other.value_;
        }

        // Hash support para std::unordered_map
        struct Hash
        {
            std::size_t operator()(const Player &player) const noexcept;
        };

    private:
        int value_;

        const char *name_;

        constexpr Player(int value, const char *name) noexcept
            : value_(value), name_(name) {}

    public:
        static const Player WHITE;

        static const Player BLACK;

        static const Player NONE;
    };

    extern const std::array<Player, 2> PLAYERS;

    inline int getPlayerDirection(const Player &player) noexcept
    {
        return player.getVectorPlayer();
    }
}

namespace std
{
    template <>
    struct hash<models::modules::game::Player>
    {
        std::size_t operator()(const models::modules::game::Player &player) const noexcept;
    };
}

#endif