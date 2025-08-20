#ifndef KING_H
#define KING_H

#include "Piece.hpp"
#include "./rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

class King : public Piece
{
public:
    King(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
