#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(Coordinate *coordinate, Color color);

    void put(Coordinate *target) override;

    bool isMovementValid(const Coordinate &target) override;

    void generateMovements() override;

    bool isThePawnPromoted() override;

    bool isVulnerablePawn() override;

    bool isInitialState();

    bool isWhite();

    bool isBlack();

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
};

#endif
