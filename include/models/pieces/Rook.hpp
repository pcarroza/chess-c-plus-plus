#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook(Coordinate *coordinate, Color color);

    std::string toString() const override;
};

#endif
