#include "common/validators/ValidatorLimitsBoard.hpp"
#include "models/modules/game/pieces/PiecesMapBuilder.hpp"
#include "models/modules/game/Board.hpp"
#include "models/modules/game/Player.hpp"

#include <iostream>
#include <assert.h>

using common::validators::ValidatorLimitsBoard;
using models::modules::game::pieces::PiecesMapBuilder;

namespace models::modules::game
{
    Board::Board()
        : piecesMap(PiecesMapBuilder::build(this)),
          selectedPieceMovements(nullptr),
          selectedPiece(nullptr),
          turn(new Turn())
    {
        removedPieces = {
            {Player::BLACK, std::vector<std::shared_ptr<Piece>>()},
            {Player::WHITE, std::vector<std::shared_ptr<Piece>>()},
        };

        inPawnInStepMap = {
            {Player::BLACK, std::vector<std::shared_ptr<Piece>>()},
            {Player::WHITE, std::vector<std::shared_ptr<Piece>>()},
        };
    }

    Board::~Board()
    {
        delete turn;
    }

    void Board::set(Piece *selectedPiece)
    {
        this->selectedPiece = selectedPiece;
    }

    void Board::set(std::vector<Coordinate> &selectedPieceMovements)
    {
        this->selectedPieceMovements = &selectedPieceMovements;
    }

    std::vector<Coordinate> &Board::getValidMovements()
    {
        return *selectedPieceMovements;
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
            set(piece->getValidMovements());
            set(piece.get());
        }
        else
        {
            assert(false && "Piece not found in this coordinate");
        }
    }

    void Board::putPieceTo(const Coordinate &coordinate)
    {
        assert(isWithinBoardLimits(coordinate) && "Invalid coordinate");
        assert(selectedPiece != nullptr && "Invalid coordinate");
        selectedPiece->put(coordinate);
    }

    bool Board::isSelectedPiece()
    {
        return selectedPiece != nullptr;
    }

    void Board::clearSelectedPiece()
    {
        selectedPiece = nullptr;
    }

    bool Board::isThePawnPromoted()
    {
        return selectedPiece != nullptr and selectedPiece->isPawnPromoted();
    }

    bool Board::isEnemy(const Coordinate &coordinate) const
    {
        auto &pieces = getPiecesBy(getRivalPlayer());
        return std::any_of(pieces.begin(), pieces.end(), [&](const std::shared_ptr<Piece> &piece)
                           { return piece->isAt(coordinate); });
    }

    bool Board::isRookAvailableForCastling(const Coordinate &coordinate) const
    {
        auto &pieces = getPiecesBy(getCurrentPlayer());
        auto it = std::find_if(pieces.begin(), pieces.end(), [&](const std::shared_ptr<Piece> &piece)
                               { return piece->isAt(coordinate); });
        return it != pieces.end() && (*it)->isRookAvailableForCastling();
    }

    bool Board::isVulnerablePawnAt(const Coordinate &coordinate) const
    {
        auto &inStepPawns = inPawnInStepMap.at(getRivalPlayer());
        return std::any_of(inStepPawns.begin(), inStepPawns.end(), [&](const std::shared_ptr<Piece> &piece)
                           { return piece->isAt(coordinate); });
    }

    bool Board::isOccupied(const Coordinate &coordinate) const
    {
        return !isSquareEmpty(coordinate);
    }

    bool Board::isKingInCheck() const
    {
        auto &pieces = getPiecesBy(getCurrentPlayer());
        auto kingIt = std::find_if(pieces.begin(), pieces.end(), [](const std::shared_ptr<Piece> &p)
                                   { return p->isKing(); });
        if (kingIt == pieces.end())
            return false;

        Coordinate kingCoord = (*kingIt)->getCoordinate();
        auto &rivalPieces = getPiecesBy(getRivalPlayer());
        return std::any_of(rivalPieces.begin(), rivalPieces.end(), [&](const std::shared_ptr<Piece> &piece)
                           { return piece->isMovementValid(kingCoord); });
    }

    bool Board::isSquareEmpty(const Coordinate &coordinate) const
    {
        auto pieceFinder = [&](const std::shared_ptr<Piece> &piece)
        {
            return piece->isAt(coordinate);
        };
        auto &currentPieces = getPiecesBy(getCurrentPlayer());

        if (std::any_of(currentPieces.begin(), currentPieces.end(), pieceFinder))
        {
            return false;
        }

        auto &rivalPieces = getPiecesBy(getRivalPlayer());

        if (std::any_of(rivalPieces.begin(), rivalPieces.end(), pieceFinder))
        {
            return false;
        }
        
        return true;
    }

    bool Board::isSameColorPieceAt(const Coordinate &coordinate) const
    {
        auto &pieces = getPiecesBy(getCurrentPlayer());

        return std::any_of(pieces.begin(), pieces.end(), [&](const std::shared_ptr<Piece> &piece)
                           { return piece->isAt(coordinate); });
    }

    bool Board::isSquareOccupied(const Coordinate &coordinate) const
    {
        return !isSquareEmpty(coordinate);
    }

    void Board::add(Piece *pawnInStep)
    {
        inPawnInStepMap.at(getCurrentPlayer()).push_back(std::shared_ptr<Piece>(pawnInStep));
    }

    bool Board::isMovementValid(const Coordinate &coordinate)
    {
        return selectedPiece->isMovementValid(coordinate);
    }

    void Board::remove(Piece *piece)
    {
        auto &inStepPawns = this->inPawnInStepMap.at(getCurrentPlayer());
        inStepPawns.erase(std::remove_if(inStepPawns.begin(), inStepPawns.end(), [piece](const std::shared_ptr<Piece> &it)
                                         { return it.get() == piece; }),
                          inStepPawns.end());
    }

    void Board::removeCurrentPlayerPiece(const Coordinate &coordinate)
    {
        removePiece(coordinate, getCurrentPlayer());
    }

    void Board::removeRivalPlayerPiece(const Coordinate &coordinate)
    {
        removePiece(coordinate, getRivalPlayer());
    }

    void Board::removePiece(const Coordinate &coordinate, Player player)
    {
        auto &pieces = piecesMap.at(player);
        auto &removed = removedPieces.at(player);

        auto it = std::remove_if(pieces.begin(), pieces.end(), [&](const std::shared_ptr<Piece> &piece)
                                 {
            if (piece->isAt(coordinate))
            {
                removed.push_back(piece);
                return true;
            }
            return false; });

        pieces.erase(it, pieces.end());
    }

    bool Board::isWithinBoardLimits(const Coordinate &coordinate)
    {
        return ValidatorLimitsBoard::getInstance().isWithinLimits(coordinate);
    }

    const std::vector<std::shared_ptr<Piece>> &Board::getPiecesBy(Player player) const
    {
        return piecesMap.at(player);
    }

    void Board::switchTurn()
    {
        turn->change();
    }

    Player Board::getCurrentPlayer() const
    {
        return turn->getCurrentPlayer();
    }

    Player Board::getRivalPlayer() const
    {
        return turn->getRivalPlayer();
    }
}