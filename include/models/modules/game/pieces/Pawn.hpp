#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"

namespace models::modules::game::pieces
{
    class Coordinate;
    class PieceVisitor;
}

namespace models::modules::game::pieces::specialRuleMovements
{
    class SpecialMovesRulesGenerator;
}

using models::modules::game::pieces::specialRuleMovements::SpecialMovesRulesGenerator;

namespace models::modules::game::pieces
{
    class Pawn : public Piece
    {
    public:
        Pawn(Coordinate *coordinate, Player player);

        ~Pawn();

        void put(Coordinate *target) override;

        bool isMovementValid(const Coordinate &target) override;

        bool isVulnerablePawn() const;

        bool isPromoted() const;

        bool isInitialState() const;

        bool canAdvanceOne() const;

        bool canAdvanceTwo() const;

        bool canCaptureLeft() const;

        bool canCaptureRight() const;

        Coordinate getForwardOne() const;

        Coordinate getForwardTwo() const;

        Coordinate getDiagonalLeft() const;

        Coordinate getDiagonalRight() const;

        void accept(PieceVisitor &pieceVisitor) override;

        std::string toString() const override;

    private:
        void close();

        bool inStep(Coordinate &target);

        bool isThePawnPromoted(Coordinate &coordinate);

        void changeToPromoted();

    private:
        bool initialState;

        bool isItPromoted;

        bool vulnerablePawn;

        SpecialMovesRulesGenerator *specialGenerator;
    };
}

#endif
