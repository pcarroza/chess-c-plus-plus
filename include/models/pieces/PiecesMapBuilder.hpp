#ifndef BUILDER_PIECES_H
#define BUILDER_PIECES_H

#include "Piece.hpp"
#include "models/Color.hpp"

#include <map>
#include <list>
#include <memory>

class BoardObserver;

class PiecesMapBuilder
{
public:
    static std::map<Color, std::list<std::shared_ptr<Piece>>> build(BoardObserver *observerBoard);

private:
    PiecesMapBuilder() = delete;

    static std::list<std::shared_ptr<Piece>> createPiecesWhite();

    static std::list<std::shared_ptr<Piece>> createPiecesBlack();

    static std::list<std::shared_ptr<Piece>> createPieces(int rowForPawnsByColor, int rowForPiecesByColor, Color color);
};

#endif
