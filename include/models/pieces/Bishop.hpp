#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"
#include "./rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

class Bishop : public Piece
{
public:
    Bishop(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
