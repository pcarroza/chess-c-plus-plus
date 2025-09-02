#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <string>
#include <memory>
#include <list>
#include <map>

#include "models/pieces/SelectedPiece.hpp"
#include "models/pieces/BoardObserver.hpp"
#include "models/pieces/Coordinate.hpp"
#include "models/pieces/Piece.hpp"
#include "BoardSubject.hpp"
#include "models/Player.hpp"
#include "models/Turn.hpp"

using models::Turn;

class Board : public BoardObserver, public BoardSubject
{
public:
    Board();

    ~Board();

    void set(Piece *piece) override;

    void set(std::list<std::shared_ptr<Coordinate>> *selectedPieceMovements) override;

    void selectPiece(const Coordinate &coordinate);

    void putPieceTo(const Coordinate &coordinate);

    bool isSelectedPiece();

    bool clearSelectedPiece();

    bool isThePawnPromoted();

    bool isEnemy(const Coordinate &coordinate) const override;

    bool isSquareEmpty(const Coordinate &coordinate) const override;

    bool isSameColorPieceAt(const Coordinate &coordinate) const override;

    bool isSquareOccupied(const Coordinate &coordinate) const override;

    bool isMovementValid(const Coordinate &coordinate);

    void add(Piece *enPassantPawn) override;

    void deleteEnPassantPawn(Piece *piece) override;

    void removeCurrentPlayerPiece(const Coordinate &coordinate);

    void removeRivalPlayerPiece(const Coordinate &coordinate);

    void changeTurn();

    bool isWithinBoardLimits(const Coordinate &coordinate);

    std::list<std::shared_ptr<Piece>> &getPiecesBy(Player player);

    Player getCurrentPlayer();

    Player getRivalPlayer();

private:
    void removePiece(const Coordinate &coordinate, Player player);

    std::map<Player, std::list<std::shared_ptr<Piece>>> piecesMap;

    std::map<Player, std::list<std::shared_ptr<Piece>>> removedPieces;

    std::map<Player, std::list<std::shared_ptr<Piece>>> enPassantPawnsMap;

    std::list<std::shared_ptr<Coordinate>> *selectedPieceMovements;

    SelectedPiece *selectedPiece;

    Turn *turn;
};

#endif
