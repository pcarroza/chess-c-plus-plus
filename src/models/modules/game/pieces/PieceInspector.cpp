#include "models/modules/game/pieces/PawnVulnerabilityVisitor.hpp"
#include "models/modules/game/pieces/PawnPromotionVisitor.hpp"
#include "models/modules/game/pieces/KingFinderVisitor.hpp"
#include "models/modules/game/pieces/RookFinderVisitor.hpp"
#include "models/modules/game/pieces/PieceInspector.hpp"
#include "models/modules/game/pieces/Piece.hpp"

namespace models::modules::game::pieces
{
    bool isPawnVulnerable(Piece &piece)
    {
        PawnVulnerabilityVisitor visitor;
        piece.accept(visitor);
        return visitor.isPawnVulnerable();
    }

    bool isPawnPromoted(Piece &piece)
    {
        PawnPromotionVisitor visitor;
        piece.accept(visitor);
        return visitor.isPawnPromoted();
    }

    bool isKing(Piece &piece)
    {
        KingFinderVisitor visitor;
        piece.accept(visitor);
        return visitor.isKingFound();
    }

    bool isRook(Piece &piece)
    {
        RookFinderVisitor visitor;
        piece.accept(visitor);
        return visitor.isRookFound();
    }
}
