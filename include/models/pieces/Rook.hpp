#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"
#include "./rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

class Rook : public Piece
{
public:
    Rook(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
