#ifndef PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP
#define PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "common/validators/ValidatorLimitsBoard.hpp"
#include "MovementRulesBaseGenerator.hpp"
#include "models/pieces/Pawn.hpp"

#include <vector>
#include <cassert>

namespace common::validators
{
    class ValidatorLimitsBoard;
}

using common::validators::ValidatorLimitsBoard;

namespace models::pieces::rulesOfMovements
{
    class PawnRuleBasedCoordinateGenerator : public MovementRulesBaseGenerator
    {
    public:
        PawnRuleBasedCoordinateGenerator(Piece *piece);

        PawnRuleBasedCoordinateGenerator() = default;

        void set(Piece *piece) override;

        void generate() override;

    private:
        std::list<std::shared_ptr<Coordinate>> calculateForwardMoves(Player color);

        std::list<std::shared_ptr<Coordinate>> calculateDiagonalCaptureMoves(Player player);

        Player getPlayer();

    private:
        Pawn *pawn;
    };
}

#endif
