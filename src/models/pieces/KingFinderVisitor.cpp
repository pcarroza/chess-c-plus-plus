#include "models/pieces/KingFinderVisitor.hpp"
#include "models/pieces/King.hpp"
#include "models/pieces/Queen.hpp"
#include "models/pieces/Rook.hpp"
#include "models/pieces/Bishop.hpp"
#include "models/pieces/Knight.hpp"
#include "models/pieces/Pawn.hpp"

KingFinderVisitor::KingFinderVisitor() : kingFound(false)
{
}

bool KingFinderVisitor::isKingFound() const
{
    return kingFound;
}

void KingFinderVisitor::visit(King &king)
{
    kingFound = true;
}

void KingFinderVisitor::visit(Queen &queen)
{
    // Do nothing
}

void KingFinderVisitor::visit(Rook &rook)
{
    // Do nothing
}

void KingFinderVisitor::visit(Bishop &bishop)
{
    // Do nothing
}

void KingFinderVisitor::visit(Knight &knight)
{
    // Do nothing
}

void KingFinderVisitor::visit(Pawn &pawn)
{
    // Do nothing
}
