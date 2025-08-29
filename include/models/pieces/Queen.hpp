#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(Coordinate *coordinate, Player color);

    void accept(PieceVisitor &visitor) override;

    std::string toString() const override;
};

#endif
