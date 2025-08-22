#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(Coordinate *coordinate, Player color);

    std::string toString() const override;
};

#endif
