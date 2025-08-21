#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
