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
        Pawn(Coordinate *coordinate, Player color);

        ~Pawn();

        void put(Coordinate *target) override;

        bool isMovementValid(const Coordinate &target) override;

        void generateMovements() override;

        bool isVulnerablePawn() const;

        bool isPromoted() const;

        bool isInitialState() const;

        bool canAdvanceOne() const;

        bool canAdvanceTwo() const;

        bool canCaptureLeft() const;

        bool canCaptureRight() const;

        std::shared_ptr<Coordinate> getForwardOne() const;

        std::shared_ptr<Coordinate> getForwardTwo() const;

        std::shared_ptr<Coordinate> getDiagonalLeft() const;

        std::shared_ptr<Coordinate> getDiagonalRight() const;

        void accept(PieceVisitor &visitor) override;

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
