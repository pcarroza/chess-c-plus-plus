#ifndef BUILDER_PIECES_H
#define BUILDER_PIECES_H

#include "Piece.hpp"
#include "models/modules/game/Player.hpp"

#include <map>
#include <list>
#include <memory>

namespace models::modules::game::pieces
{
    class BoardObserver;
}

namespace models::modules::game::pieces
{
    class PiecesMapBuilder
    {
    public:
        static std::map<Player, std::list<std::shared_ptr<Piece>>> build(BoardObserver *observerBoard);

    private:
        PiecesMapBuilder() = delete;

        static std::list<std::shared_ptr<Piece>> createPiecesWhite();

        static std::list<std::shared_ptr<Piece>> createPiecesBlack();

        static std::list<std::shared_ptr<Piece>> createPieces(int rowForPawnsByColor, int rowForPiecesByColor, Player color);
    };
}

#endif
