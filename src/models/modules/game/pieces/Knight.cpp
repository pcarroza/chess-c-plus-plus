#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"

namespace models::modules::game::pieces
{
    Knight::Knight(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = rules::createKnightRuleBasedCoordinateGenerator(this);
    }

    void Knight::accept(PieceVisitor &pieceVisitor)
    {
        pieceVisitor.visit(*this);
    }

    std::string Knight::toString() const
    {
        return "Knight()";
    }
}
