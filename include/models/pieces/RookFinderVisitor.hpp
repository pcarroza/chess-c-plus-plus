#ifndef ROOK_FINDER_VISITOR_HPP
#define ROOK_FINDER_VISITOR_HPP

#include "PieceVisitor.hpp"

class RookFinderVisitor : public PieceVisitor
{
public:
    RookFinderVisitor();

    bool isRookFound() const;

    void visit(King &king) override;

    void visit(Queen &queen) override;

    void visit(Rook &rook) override;

    void visit(Bishop &bishop) override;

    void visit(Knight &knight) override;

    void visit(Pawn &pawn) override;

private:
    bool rookFound;
};

#endif
