#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::modules::game::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

namespace models::modules::game::pieces
{
    King::King(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(this);
    }

    void King::accept(PieceVisitor &visitor)
    {
        visitor.visit(*this);
    }

    std::string King::toString() const
    {
        return "King()";
    }
}
