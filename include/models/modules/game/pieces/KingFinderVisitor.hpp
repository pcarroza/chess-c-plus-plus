#ifndef KING_FINDER_VISITOR_HPP
#define KING_FINDER_VISITOR_HPP

#include "PieceVisitor.hpp"

namespace models::modules::game::pieces
{
    class King;
    class Queen;
    class Rook;
    class Bishop;
    class Knight;
    class Pawn;
}

namespace models::modules::game::pieces
{
    class KingFinderVisitor : public PieceVisitor
    {
    public:
        KingFinderVisitor();

        bool isKingFound() const;

        void visit(King &king) override;

        void visit(Queen &queen) override;

        void visit(Rook &rook) override;

        void visit(Bishop &bishop) override;

        void visit(Knight &knight) override;

        void visit(Pawn &pawn) override;

    private:
        bool kingFound;
    };
}

#endif
