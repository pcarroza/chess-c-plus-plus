#include "models/pieces/PawnPromotionVisitor.hpp"
#include "models/pieces/King.hpp"
#include "models/pieces/Queen.hpp"
#include "models/pieces/Rook.hpp"
#include "models/pieces/Bishop.hpp"
#include "models/pieces/Knight.hpp"
#include "models/pieces/Pawn.hpp"

PawnPromotionVisitor::PawnPromotionVisitor() : pawnPromoted(false)
{
}

bool PawnPromotionVisitor::isPawnPromoted() const
{
    return pawnPromoted;
}

void PawnPromotionVisitor::visit(Pawn &pawn)
{
    pawnPromoted = pawn.isPromoted();
}

void PawnPromotionVisitor::visit(King &king)
{
    // Do nothing
}

void PawnPromotionVisitor::visit(Queen &queen)
{
    // Do nothing
}

void PawnPromotionVisitor::visit(Rook &rook)
{
    // Do nothing
}

void PawnPromotionVisitor::visit(Bishop &bishop)
{
    // Do nothing
}

void PawnPromotionVisitor::visit(Knight &knight)
{
    // Do nothing
}
