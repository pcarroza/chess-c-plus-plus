#include "models/modules/game/pieces/rules/GeneratorRegistry.hpp"
#include "models/modules/game/pieces/rules/MovementRulesGeneratorFactory.hpp"

#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/King.hpp"

#include "models/modules/game/pieces/rules/PawnRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/BishopRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KnightRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/RookRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/QueenRuleBasedCoordinateGenerator.hpp"
#include "models/modules/game/pieces/rules/KingRuleBasedCoordinateGenerator.hpp"

namespace models::modules::game::pieces::rules
{
    void GeneratorRegistry::registerAll(MovementRulesGeneratorFactory &factory)
    {
        factory.registerGenerator<Pawn, PawnRuleBasedCoordinateGenerator>();
        factory.registerGenerator<Rook, RookRuleBasedCoordinateGenerator>();
        factory.registerGenerator<Knight, KnightRuleBasedCoordinateGenerator>();
        factory.registerGenerator<Bishop, BishopRuleBasedCoordinateGenerator>();
        factory.registerGenerator<Queen, QueenRuleBasedCoordinateGenerator>();
        factory.registerGenerator<King, KingRuleBasedCoordinateGenerator>();
    }
}
