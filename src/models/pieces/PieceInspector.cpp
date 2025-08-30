#include "models/pieces/PieceInspector.hpp"
#include "models/pieces/PawnVulnerabilityVisitor.hpp"
#include "models/pieces/PawnPromotionVisitor.hpp"
#include "models/pieces/KingFinderVisitor.hpp"
#include "models/pieces/RookFinderVisitor.hpp"
#include "models/pieces/Piece.hpp"

bool PieceInspector::isPawnVulnerable(Piece &piece)
{
    PawnVulnerabilityVisitor visitar;
    piece.accept(visitar);
    return visitar.isPawnVulnerable();
}

bool PieceInspector::isPawnPromoted(Piece &piece)
{
    PawnPromotionVisitor visitar;
    piece.accept(visitar);
    return visitar.isPawnPromoted();
}

bool PieceInspector::isKing(Piece &piece)
{
    KingFinderVisitor visitar;
    piece.accept(visitar);
    return visitar.isKingFound();
}

bool PieceInspector::isRook(Piece &piece)
{
    RookFinderVisitor vistar;
    piece.accept(vistar);
    return vistar.isRookFound();
}