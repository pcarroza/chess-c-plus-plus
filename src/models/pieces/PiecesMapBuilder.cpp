#include "models/pieces/Coordinate.hpp"
#include "models/pieces/PiecesMapBuilder.hpp"
#include "models/pieces/Knight.hpp"
#include "models/pieces/Bishop.hpp"
#include "models/pieces/Queen.hpp"
#include "models/pieces/Pawn.hpp"
#include "models/pieces/Rook.hpp"
#include "models/pieces/King.hpp"

#include <map>
#include <list>
#include <memory>
#include <iostream>

std::map<Color, std::list<std::shared_ptr<Piece>>> PiecesMapBuilder::build(BoardObserver *observerBoard)
{
    std::map<Color, std::list<std::shared_ptr<Piece>>> piecesMap = {
        {Color::BLACK, createPiecesBlack()},
        {Color::WHITE, createPiecesWhite()},
    };

    for (auto &pieces : piecesMap)
    {
        for (auto &piece : pieces.second)
        {
            piece->subscribe(observerBoard);
        }
    }
    return piecesMap;
}

std::list<std::shared_ptr<Piece>> PiecesMapBuilder::createPiecesWhite()
{
    int rowForPawnsByColor = 2;
    int rowForPiecesByColor = 1;
    return createPieces(rowForPawnsByColor, rowForPiecesByColor, Color::WHITE);
}

std::list<std::shared_ptr<Piece>> PiecesMapBuilder::createPiecesBlack()
{
    int rowForPawnsByColor = 7;
    int rowForPiecesByColor = 8;
    return createPieces(rowForPawnsByColor, rowForPiecesByColor, Color::BLACK);
}

std::list<std::shared_ptr<Piece>> PiecesMapBuilder::createPieces(int rowForPawnsByColor, int rowForPiecesByColor, Color color)
{
    std::list<std::shared_ptr<Piece>> pieces;
    for (size_t i = 1; i <= 8; i++)
    {
        pieces.push_back(std::make_shared<Pawn>(new Coordinate(rowForPawnsByColor, i), color));
    }
    pieces.push_back(std::make_shared<Rook>(new Coordinate(rowForPiecesByColor, 1), color));
    pieces.push_back(std::make_shared<Knight>(new Coordinate(rowForPiecesByColor, 2), color));
    pieces.push_back(std::make_shared<Bishop>(new Coordinate(rowForPiecesByColor, 3), color));
    pieces.push_back(std::make_shared<King>(new Coordinate(rowForPiecesByColor, 4), color));
    pieces.push_back(std::make_shared<Queen>(new Coordinate(rowForPiecesByColor, 5), color));
    pieces.push_back(std::make_shared<Bishop>(new Coordinate(rowForPiecesByColor, 6), color));
    pieces.push_back(std::make_shared<Knight>(new Coordinate(rowForPiecesByColor, 7), color));
    pieces.push_back(std::make_shared<Rook>(new Coordinate(rowForPiecesByColor, 8), color));
    return pieces;
}
