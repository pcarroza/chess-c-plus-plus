#include "models/pieces/RookFinderVisitor.hpp"
#include "models/pieces/King.hpp"
#include "models/pieces/Queen.hpp"
#include "models/pieces/Rook.hpp"
#include "models/pieces/Bishop.hpp"
#include "models/pieces/Knight.hpp"
#include "models/pieces/Pawn.hpp"

RookFinderVisitor::RookFinderVisitor() : rookFound(false)
{
}

bool RookFinderVisitor::isRookFound() const
{
    return rookFound;
}

void RookFinderVisitor::visit(Rook &rook)
{
    rookFound = true;
}

void RookFinderVisitor::visit(King &king)
{
    // Do nothing
}

void RookFinderVisitor::visit(Queen &queen)
{
    // Do nothing
}

void RookFinderVisitor::visit(Bishop &bishop)
{
    // Do nothing
}

void RookFinderVisitor::visit(Knight &knight)
{
    // Do nothing
}

void RookFinderVisitor::visit(Pawn &pawn)
{
    // Do nothing
}
