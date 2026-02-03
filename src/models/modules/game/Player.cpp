#include "models/modules/game/Player.hpp"
#include <stdexcept>
#include <functional>

using models::modules::game::Player;

namespace models::modules::game
{
    // ========================================================================
    // Definición de instancias estáticas
    // ========================================================================

    const Player Player::WHITE{1, "WHITE"};

    const Player Player::BLACK{-1, "BLACK"};

    const Player Player::NONE{0, "NONE"};

    // Array de jugadores válidos
    const std::array<Player, 2> PLAYERS = {Player::WHITE, Player::BLACK};

    // ========================================================================
    // Métodos con lógica compleja
    // ========================================================================

    const Player &Player::getOpponent() const
    {
        if (*this == WHITE)
        {
            return BLACK;
        }
        if (*this == BLACK)
        {
            return WHITE;
        }
        throw std::logic_error("NONE player has no opponent");
    }

    // ========================================================================
    // Factory method
    // ========================================================================

    const Player &Player::fromValue(int value)
    {
        switch (value)
        {
        case 1:
            return WHITE;
        case -1:
            return BLACK;
        case 0:
            return NONE;
        default:
            throw std::invalid_argument("Invalid player value: " + std::to_string(value) + ". Expected 1 (WHITE), -1 (BLACK), or 0 (NONE).");
        }
    }

    // ========================================================================
    // Hash support
    // ========================================================================

    std::size_t Player::Hash::operator()(const Player &player) const noexcept
    {
        return std::hash<int>{}(player.value_);
    }

} // namespace models::modules::game

// ============================================================================
// Especialización de std::hash
// ============================================================================

namespace std
{
    std::size_t hash<Player>::operator()(const Player &player) const noexcept
    {
        return hash<int>{}(player.getValue());
    }
}