#include "models/modules/game/pieces/PawnPromotionVisitor.hpp"
#include "models/modules/game/pieces/King.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Pawn.hpp"

namespace models::modules::game::pieces
{

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
}
