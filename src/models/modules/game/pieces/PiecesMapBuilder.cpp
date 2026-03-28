#include "models/modules/game/pieces/PiecesMapBuilder.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Knight.hpp"
#include "models/modules/game/pieces/Bishop.hpp"
#include "models/modules/game/pieces/Queen.hpp"
#include "models/modules/game/pieces/Pawn.hpp"
#include "models/modules/game/pieces/Rook.hpp"
#include "models/modules/game/pieces/King.hpp"

#include <map>
#include <list>
#include <memory>
#include <iostream>

namespace models::modules::game::pieces
{
    std::map<Player, std::vector<std::shared_ptr<Piece>>> PiecesMapBuilder::build(BoardObserver *observerBoard)
    {
        std::map<Player, std::vector<std::shared_ptr<Piece>>> piecesMap = {
            {Player::WHITE, createPiecesWhite()},
            {Player::BLACK, createPiecesBlack()}};

        for (auto &pieces : piecesMap)
        {
            for (auto &piece : pieces.second)
            {
                piece->subscribe(observerBoard);
            }
        }
        return piecesMap;
    }

    std::vector<std::shared_ptr<Piece>> PiecesMapBuilder::createPiecesWhite()
    {
        int rowForPawnsByColor = 2;
        int rowForPiecesByColor = 1;
        return createPieces(rowForPawnsByColor, rowForPiecesByColor, Player::WHITE);
    }

    std::vector<std::shared_ptr<Piece>> PiecesMapBuilder::createPiecesBlack()
    {
        int rowForPawnsByColor = 7;
        int rowForPiecesByColor = 8;
        return createPieces(rowForPawnsByColor, rowForPiecesByColor, Player::BLACK);
    }

    std::vector<std::shared_ptr<Piece>> PiecesMapBuilder::createPieces(int rowForPawnsByColor, int rowForPiecesByColor, Player player)
    {
        std::vector<std::shared_ptr<Piece>> pieces;
        pieces.reserve(16);
        const int NUMBER_MAX_PAWNS = 8;
        for (size_t i = 1; i <= NUMBER_MAX_PAWNS; i++)
        {
            pieces.push_back(std::make_shared<Pawn>(Coordinate(rowForPawnsByColor, i), player));
        }
        pieces.push_back(std::make_shared<Rook>(Coordinate(rowForPiecesByColor, 1), player));
        pieces.push_back(std::make_shared<Knight>(Coordinate(rowForPiecesByColor, 2), player));
        pieces.push_back(std::make_shared<Bishop>(Coordinate(rowForPiecesByColor, 3), player));
        pieces.push_back(std::make_shared<King>(Coordinate(rowForPiecesByColor, 4), player));
        pieces.push_back(std::make_shared<Queen>(Coordinate(rowForPiecesByColor, 5), player));
        pieces.push_back(std::make_shared<Bishop>(Coordinate(rowForPiecesByColor, 6), player));
        pieces.push_back(std::make_shared<Knight>(Coordinate(rowForPiecesByColor, 7), player));
        pieces.push_back(std::make_shared<Rook>(Coordinate(rowForPiecesByColor, 8), player));
        return pieces;
    }
}
