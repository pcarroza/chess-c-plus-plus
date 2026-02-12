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

    void KingFinderVisitor::visit([[maybe_unused]] King &king)
    {
        kingFound = true;
    }

    void KingFinderVisitor::visit([[maybe_unused]] Queen &queen)
    {
        // Do nothing
    }

    void KingFinderVisitor::visit([[maybe_unused]] Rook &rook)
    {
        // Do nothing
    }

    void KingFinderVisitor::visit([[maybe_unused]] Bishop &bishop)
    {
        // Do nothing
    }

    void KingFinderVisitor::visit([[maybe_unused]] Knight &knight)
    {
        // Do nothing
    }

    void KingFinderVisitor::visit([[maybe_unused]] Pawn &pawn)
    {
        // Do nothing
    }
}
