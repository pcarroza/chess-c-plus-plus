#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::modules::game::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

namespace models::modules::game::pieces
{
    Knight::Knight(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(this);
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
