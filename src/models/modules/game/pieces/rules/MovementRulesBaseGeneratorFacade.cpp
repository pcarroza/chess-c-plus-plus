#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"
#include "models/modules/game/pieces/rules/BishopRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KingRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KnightRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/QueenRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/RookRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/PawnRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new BishopRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new KingRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new KnightRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new QueenRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new RookRuleBasedCoordinateGenerator(piece);
    }

    MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator(Piece *piece)
    {
        return new PawnRuleBasedCoordinateGenerator(piece);
    }
}