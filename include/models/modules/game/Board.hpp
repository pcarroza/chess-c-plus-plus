#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <string>
#include <memory>
#include <list>
#include <map>

#include "models/modules/game/pieces/SelectedPiece.hpp"
#include "models/modules/game/pieces/BoardObserver.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/BoardSubject.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/Turn.hpp"

using models::modules::game::Player;
using models::modules::game::Turn;
using models::modules::game::pieces::BoardObserver;
using models::modules::game::pieces::BoardSubject;
using models::modules::game::pieces::Coordinate;
using models::modules::game::pieces::Piece;
using models::modules::game::pieces::SelectedPiece;

namespace models::modules::game
{
    class Board : public BoardObserver, public BoardSubject
    {
    public:
        Board();

        ~Board();

        void set(Piece *piece) override;

        void set(std::list<std::shared_ptr<Coordinate>> &selectedPieceMovements) override;

        std::list<std::shared_ptr<Coordinate>> &getValidMovements();

        void selectPiece(const Coordinate &coordinate);

        void putPieceTo(const Coordinate &coordinate);

        bool isSelectedPiece();

        void clearSelectedPiece();

        bool isThePawnPromoted();

        bool isEnemy(const Coordinate &coordinate) override;

        bool isSquareEmpty(const Coordinate &coordinate) override;

        bool isSameColorPieceAt(const Coordinate &coordinate) override;

        bool isSquareOccupied(const Coordinate &coordinate) override;

        bool isMovementValid(const Coordinate &coordinate);

        void add(Piece *enPassantPawn) override;

        void deletedPawnInStep(Piece *piece) override;

        void removeCurrentPlayerPiece(const Coordinate &coordinate);

        void removeRivalPlayerPiece(const Coordinate &coordinate);

        bool isWithinBoardLimits(const Coordinate &coordinate);

        std::list<std::shared_ptr<Piece>> &getPiecesBy(Player player);

        void changeTurn();

        Player getCurrentPlayer();

        Player getRivalPlayer();

    private:
        void removePiece(const Coordinate &coordinate, Player player);

    private:
        std::map<Player, std::list<std::shared_ptr<Piece>>> piecesMap;

        std::map<Player, std::list<std::shared_ptr<Piece>>> removedPieces;

        std::map<Player, std::list<std::shared_ptr<Piece>>> inStepPawnsMap;

        std::list<std::shared_ptr<Coordinate>> *selectedPieceMovements;

        SelectedPiece *selectedPiece;

        Turn *turn;
    };
}

#endif