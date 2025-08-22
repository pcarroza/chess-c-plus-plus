#ifndef KING_H
#define KING_H

#include "Piece.hpp"

class King : public Piece
{
public:
    King(Coordinate *coordinate, Player color);

    std::string toString() const override;
};

#endif
