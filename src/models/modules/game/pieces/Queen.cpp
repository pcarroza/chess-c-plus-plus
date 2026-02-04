#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"

namespace models::modules::game::pieces
{
    Queen::Queen(Coordinate *coordinate, Player color) : Piece(coordinate, color)
    {
        basedGenerator = rules::createQueenRuleBasedCoordinateGenerator(this);
    }

    void Queen::accept(PieceVisitor &visitor)
    {
        visitor.visit(*this);
    }

    std::string Queen::toString() const
    {
        return "Queen()";
    }
}
