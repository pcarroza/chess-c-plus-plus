#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"

namespace models::modules::game::pieces
{
    Queen::Queen(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = rules::createQueenRuleBasedCoordinateGenerator();
    }

    void Queen::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Queen::toString() const
    {
        return "Queen()";
    }
}
