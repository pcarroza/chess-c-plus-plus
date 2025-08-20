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

        static MovementRulesBaseGeneratorGenerator *createBishopRuleBasedCoordinateGenerator(Piece &piece);

        static MovementRulesBaseGeneratorGenerator *createKingRuleBasedCoordinateGenerator(Piece &piece);

        static MovementRulesBaseGeneratorGenerator *createKnightRuleBasedCoordinateGenerator(Piece &piece);

        static MovementRulesBaseGeneratorGenerator *createQueenRuleBasedCoordinateGenerator(Piece &piece);

        static MovementRulesBaseGeneratorGenerator *createRookRuleBasedCoordinateGenerator(Piece &piece);

        static MovementRulesBaseGeneratorGenerator *createPawnRuleBasedCoordinateGenerator(Piece &piece);
    };
}
#endif
