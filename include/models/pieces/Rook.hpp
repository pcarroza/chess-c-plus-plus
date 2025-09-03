#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook(Coordinate *coordinate, Player color);

    void accept(PieceVisitor &visitor) override;

    std::string toString() const override;
};

#endif
