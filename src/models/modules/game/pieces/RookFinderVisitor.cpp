#include "models/modules/game/pieces/RookFinderVisitor.hpp"
#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Pawn.hpp"

namespace models::modules::game::pieces
{
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
}
