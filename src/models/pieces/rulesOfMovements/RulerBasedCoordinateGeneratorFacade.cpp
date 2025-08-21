#include "models/pieces/rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

namespace models::pieces::rulesOfMovements
{
    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new BishopRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new KingRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new KnightRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createQueenRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new QueenRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new RookRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *MovementRulesBaseGeneratorFacade::createPawnRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new PawnRuleBasedCoordinateGenerator(piece);
    }
}