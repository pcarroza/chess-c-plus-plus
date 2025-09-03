#ifndef PIECE_VISITOR_HPP
#define PIECE_VISITOR_HPP

class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;

class PieceVisitor
{
public:
    virtual ~PieceVisitor() = default;

    virtual void visit(King &king) = 0;

    virtual void visit(Queen &queen) = 0;

    virtual void visit(Rook &rook) = 0;

    virtual void visit(Bishop &bishop) = 0;

    virtual void visit(Knight &knight) = 0;

    virtual void visit(Pawn &pawn) = 0;
};

#endif
