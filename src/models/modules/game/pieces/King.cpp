#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"


namespace models::modules::game::pieces
{
    King::King(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = rules::createKingRuleBasedCoordinateGenerator();
    }

    void King::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string King::toString() const
    {
        return "King()";
    }
}
