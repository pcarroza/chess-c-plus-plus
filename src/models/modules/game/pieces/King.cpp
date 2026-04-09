#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"

namespace models::modules::game::pieces
{
    King::King(Coordinate coordinate, Player color) : Piece(coordinate, color)
    {
        movementRulesGenerator = const_cast<rules::MovementRulesGenerator *>(&rules::MovementRulesFacade::getKingRules());
    }

    void King::put(Coordinate coordinate)
    {
        if (!isMoved)
        {
            close();
        }
        Piece::put(coordinate);
    }

    bool King::isMovementValid(const Coordinate &target) const
    {
        return Piece::isMovementValid(target);
    };

    void King::close()
    {
        isMoved = true;
    }

    PieceSymbol King::getSymbol() const
    {
        return PieceSymbol::KING;
    }
}
