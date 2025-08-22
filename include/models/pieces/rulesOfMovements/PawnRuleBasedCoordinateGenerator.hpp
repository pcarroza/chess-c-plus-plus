#ifndef PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP
#define PAWN_RULE_BASED_COORDINATE_GENERATOR_HPP

#include "MovementRulesBaseGenerator.hpp"
#include "models/pieces/Pawn.hpp"

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

        void addCaptureMoveIfValid(Coordinate coordinate);

        Player getPlayer();

    private:
        Pawn *pawn;
    };
}

#endif
