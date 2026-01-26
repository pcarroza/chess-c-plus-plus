#ifndef PAWN_PROMOTION_VISITOR_HPP
#define PAWN_PROMOTION_VISITOR_HPP

#include "PieceVisitor.hpp"

class PawnPromotionVisitor : public PieceVisitor
{
public:
    PawnPromotionVisitor();

    bool isPawnPromoted() const;

    void visit(King &king) override;

    void visit(Queen &queen) override;

    void visit(Rook &rook) override;

    void visit(Bishop &bishop) override;

    void visit(Knight &knight) override;

    void visit(Pawn &pawn) override;

private:
    bool pawnPromoted;
};

#endif
