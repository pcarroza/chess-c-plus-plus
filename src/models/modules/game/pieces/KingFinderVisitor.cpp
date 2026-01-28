#include "models/modules/game/pieces/KingFinderVisitor.hpp"
#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Pawn.hpp"

namespace models::modules::game::pieces
{
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
}
