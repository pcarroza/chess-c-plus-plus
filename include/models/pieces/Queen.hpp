#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"
#include "./rulesOfMovements/RulerBasedCoordinateGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

class Queen : public Piece
{
public:
    Queen(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
