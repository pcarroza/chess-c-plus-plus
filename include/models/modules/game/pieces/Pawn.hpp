#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/special/EnPassantPawnSpecialRuleGenerator.hpp"

namespace models::modules::game::pieces
{
    class Coordinate;
    class PieceVisitor;
}

using models::modules::game::pieces::special::EnPassantPawnSpecialRuleGenerator;

namespace models::modules::game::pieces
{
    class Pawn : public Piece
    {
    public:
        Pawn(Coordinate coordinate, Player player);

        ~Pawn();

        void put(Coordinate target) override;

        bool isMovementValid(const Coordinate &target) const override;

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

        PieceSymbol getSymbol() const override;

    private:
        void close();

        bool inStep(Coordinate target);

        bool isThePawnPromoted(Coordinate coordinate);

        void changeToPromoted();

    private:
        bool initialState;

        bool isItPromoted;

        bool vulnerablePawn;

        EnPassantPawnSpecialRuleGenerator specialGenerator;
    };
}

#endif
