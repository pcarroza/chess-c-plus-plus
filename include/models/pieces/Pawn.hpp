#ifndef PAWN_H
#define PAWN_H

#include "models/pieces/specialRuleMovements/SpecialMovesRulesGenerator.hpp"
#include "Piece.hpp"

namespace models::pieces::specialRuleMovements
{
    class SpecialMovesRulesGenerator;
}

using models::pieces::specialRuleMovements::SpecialMovesRulesGenerator;

class Pawn : public Piece
{
public:
    Pawn(Coordinate *coordinate, Player color);

    void put(Coordinate *target) override;

    bool isMovementValid(const Coordinate &target) override;

    void generateMovements() override;

    bool isThePawnPromoted() override;

    bool isVulnerablePawn() override;

    bool isInitialState() const;

    bool isWhite();

    bool isBlack();

    bool canAdvanceOne() const;

    bool canAdvanceTwo() const;

    bool canCaptureLeft() const;

    bool canCaptureRight() const;

    std::shared_ptr<Coordinate> getForwardOne() const;

    std::shared_ptr<Coordinate> getForwardTwo() const;

    std::shared_ptr<Coordinate> getDiagonalLeft() const;

    std::shared_ptr<Coordinate> getDiagonalRight() const;

    std::string toString() const override;

private:
    void close();

    bool inStep(Coordinate &target);

    bool isThePawnPromoted(Coordinate &coordinate);

    void changeToPromoted();

    int getPlayerValue(Player player);

private:
    bool initialState;

    bool isItPromoted;

    bool vulnerablePawn;

    SpecialMovesRulesGenerator *specialGenerator;
};

#endif
