#include "models/modules/game/pieces/rules/MovementRulesGeneratorFactory.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/King.hpp"

using namespace models::modules::game::pieces;

namespace models::modules::game::pieces::rules
{
    MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<Bishop>();
    }

    MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<King>();
    }

    MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<Knight>();
    }

    MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<Queen>();
    }

    MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<Rook>();
    }

    MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator()
    {
        return MovementRulesGeneratorFactory::getInstance().getGenerator<Pawn>();
    }
}