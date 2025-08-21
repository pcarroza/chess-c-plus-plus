#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
