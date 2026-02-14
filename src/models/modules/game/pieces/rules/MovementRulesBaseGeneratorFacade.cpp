#include "models/modules/game/pieces/rules/MovementRulesBaseGeneratorFacade.hpp"
#include "models/modules/game/pieces/rules/BishopRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KingRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KnightRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/QueenRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/RookRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/PawnRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator()
    {
        return new BishopRuleBasedCoordinateGenerator();
    }

    MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator()
    {
        return new KingRuleBasedCoordinateGenerator();
    }

    MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator()
    {
        return new KnightRuleBasedCoordinateGenerator();
    }

    MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator()
    {
        return new QueenRuleBasedCoordinateGenerator();
    }

    MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator()
    {
        return new RookRuleBasedCoordinateGenerator();
    }

    MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator()
    {
        return new PawnRuleBasedCoordinateGenerator();
    }
}