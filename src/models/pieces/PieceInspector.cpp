#include "models/pieces/PieceInspector.hpp"
#include "models/pieces/PawnVulnerabilityVisitor.hpp"
#include "models/pieces/PawnPromotionVisitor.hpp"
#include "models/pieces/KingFinderVisitor.hpp"
#include "models/pieces/RookFinderVisitor.hpp"
#include "models/pieces/Piece.hpp"

bool PieceInspector::isPawnVulnerable(Piece &piece)
{
    PawnVulnerabilityVisitor visitor;
    piece.accept(visitor);
    return visitor.isPawnVulnerable();
}

bool PieceInspector::isPawnPromoted(Piece &piece)
{
    PawnPromotionVisitor visitor;
    piece.accept(visitor);
    return visitor.isPawnPromoted();
}

bool PieceInspector::isKing(Piece &piece)
{
    KingFinderVisitor visitor;
    piece.accept(visitor);
    return visitor.isKingFound();
}

bool PieceInspector::isRook(Piece &piece)
{
    RookFinderVisitor visitor;
    piece.accept(visitor);
    return visitor.isRookFound();
}