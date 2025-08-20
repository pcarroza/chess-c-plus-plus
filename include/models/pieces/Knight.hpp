#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"
#include "./rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

class Knight : public Piece
{
public:
    Knight(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
