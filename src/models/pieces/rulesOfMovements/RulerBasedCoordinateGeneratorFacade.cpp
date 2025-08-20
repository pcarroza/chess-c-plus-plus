#include "models/pieces/rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

namespace models::pieces::rulesOfMovements
{
    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createBishopRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new BishopRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createKingRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new KingRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createKnightRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new KnightRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createQueenRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new QueenRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createRookRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new RookRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGeneratorGenerator *MovementRulesBaseGeneratorFacade::createPawnRuleBasedCoordinateGenerator(Piece &piece)
    {
        return new PawnRuleBasedCoordinateGenerator(piece);
    }
}