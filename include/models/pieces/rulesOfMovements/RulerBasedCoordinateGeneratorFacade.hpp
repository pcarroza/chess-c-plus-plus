#ifndef RULER_BASED_COORDINATE_GENERATOR_FACADE_HPP
#define RULER_BASED_COORDINATE_GENERATOR_FACADE_HPP

#include "RuleBasedCoordinateGenerator.hpp"
#include "KingRuleBasedCoordinateGenerator.hpp"
#include "KnightRuleBasedCoordinateGenerator.hpp"
#include "BishopRuleBasedCoordinateGenerator.hpp"
#include "QueenRuleBasedCoordinateGenerator.hpp"
#include "RookRuleBasedCoordinateGenerator.hpp"
#include "PawnRuleBasedCoordinateGenerator.hpp"
#include "../Piece.hpp"

#include <list>
#include <memory>

namespace models::pieces::rulesOfMovements
{
    class MovementRulesBaseGeneratorFacade
    {
    public:
        MovementRulesBaseGeneratorFacade() = delete;

        static MovementRulesBaseGenerator *createBishopRuleBasedCoordinateGenerator(Piece *piece);

        static MovementRulesBaseGenerator *createKingRuleBasedCoordinateGenerator(Piece *piece);

        static MovementRulesBaseGenerator *createKnightRuleBasedCoordinateGenerator(Piece *piece);

        static MovementRulesBaseGenerator *createQueenRuleBasedCoordinateGenerator(Piece *piece);

        static MovementRulesBaseGenerator *createRookRuleBasedCoordinateGenerator(Piece *piece);

        static MovementRulesBaseGenerator *createPawnRuleBasedCoordinateGenerator(Piece *piece);
    };
}
#endif
