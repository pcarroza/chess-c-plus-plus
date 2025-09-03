#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(Coordinate *coordinate, Player color);

    void accept(PieceVisitor &visitor) override;

    std::string toString() const override;
};

#endif
