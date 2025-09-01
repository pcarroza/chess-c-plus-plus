#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/pieces/PiecesMapBuilder.hpp"
#include "models/pieces/PieceInspector.hpp"
#include "models/Board.hpp"

#include <iostream>
#include <assert.h>

using common::validators::ValidatorLimitsBoard;

Board::Board()
    : piecesMap(PiecesMapBuilder::build(this)),
      selectedPiece(nullptr),
      selectedPieceMovements(nullptr),
      turn(new Turn())
{
}

Board::~Board()
{
    delete turn;
}

void Board::set(Piece *piece)
{
    this->selectedPiece = piece;
}

void Board::set(std::list<std::shared_ptr<Coordinate>> *selectedPieceMovements)
{
    this->selectedPieceMovements = selectedPieceMovements;
}

void Board::selectPiece(const Coordinate &coordinate)
{
    assert(isWithinBoardLimits(coordinate) && "Invalid coordinate");
    assert(!isSquareEmpty(coordinate) && "Invalid coordinate");

    auto &pieces = getPiecesBy(getCurrentPlayer());

    auto it = std::find_if(pieces.begin(), pieces.end(), [&](const std::shared_ptr<Piece> &piece)
                           { return piece->isAt(coordinate); });

    if (it != pieces.end())
    {
        auto &piece = *it;
        piece->generateMovements();
        set(&piece->getValidMovements());
        selectedPiece = piece.get();
    }
    else
    {
        assert(false && "Piece not found in this coordinate");
    }
    std::cout << "Piece selected at: " << coordinate << std::endl;
    std::cout << "Selected piece: " << selectedPiece << std::endl;
}

void Board::putPieceTo(const Coordinate &coordinate)
{
    assert(isWithinBoardLimits(coordinate) && "Invalid coordinate");
    assert(selectedPiece != nullptr && "Invalid coordinate");
    selectedPiece->put(new Coordinate(coordinate));
    std::cout << "Piece put at: " << coordinate << std::endl;
}

bool Board::isSelectedPiece()
{
    return selectedPiece != nullptr;
}

bool Board::clearSelectedPiece()
{
    return selectedPiece = nullptr;
}

bool Board::isThePawnPromoted()
{
    return PieceInspector::isPawnPromoted(*static_cast<Piece *>(selectedPiece));
}

bool Board::isEnemy(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::isSquareEmpty(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::isSameColorPieceAt(const Coordinate & /*coordinate*/) const
{
    return false;
}

bool Board::isSquareOccupied(const Coordinate & /*coordinate*/) const
{
    return false;
}

void Board::add(Piece *enPassantPawns)
{
    enPassantPawnsMap.at(getCurrentPlayer()).push_back(std::shared_ptr<Piece>(enPassantPawns));
}

bool Board::isMovementValid(const Coordinate &coordinate)
{
    return selectedPiece->isMovementValid(coordinate);
}

void Board::deleteEnPassantPawn(Piece *piece)
{
    std::cout << piece << std::endl;
}

void Board::removeCurrentPlayerPiece(const Coordinate & /*coordinate*/)
{
    std::cout << "" << std::endl;
}

void Board::removeRivalPlayerPiece(const Coordinate & /*coordinate*/)
{
    std::cout << "" << std::endl;
}

void Board::changeTurn()
{
    turn->change();
}

bool Board::isWithinBoardLimits(const Coordinate &coordinate)
{
    return ValidatorLimitsBoard::getInstance().isWithinLimits(coordinate);
}

std::list<std::shared_ptr<Piece>> &Board::getPiecesBy(Player player)
{
    return piecesMap.at(player);
}

Player Board::getCurrentPlayer()
{
    return turn->getCurrentPlayer();
}

Player Board::getRivalPlayer()
{
    return turn->getRivalPlayer();
}
