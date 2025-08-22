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
#include "models/Color.hpp"
#include "models/Turn.hpp"

using models::Turn;

class Board : public BoardObserver, public BoardSubject
{
public:
    Board();

    ~Board();

    void set(Piece *piece) override;

    void set(std::list<std::shared_ptr<Coordinate>> movementsSelectedPiece) override;

    bool isItEnemy(const Coordinate &coordinate) const override;

    bool isBoxEmpty(const Coordinate &coordinate) const override;

    bool someColor(const Coordinate &coordinate) const override;

    bool isBoxOccupied(const Coordinate &coordinate) const override;

    bool isMovementValid(const Coordinate &coordinate);

    void add(Piece *enPassantPawn) override;

    void selectPiece(const Coordinate &coordinate);

    void putPiece(const Coordinate &coordinate);

    void removeCurrentPlayerPiece(const Coordinate &coordinate);

    void removeRivalPlayerPiece(const Coordinate &coordinate);

    void changeTurn();

private:
    std::map<Player, std::list<std::shared_ptr<Piece>>> piecesMap;

    std::map<Player, std::list<std::shared_ptr<Piece>>> mapOfRemovedPieces;

    std::map<Player, std::list<std::shared_ptr<Piece>>> mapPassantPawns;

    std::list<std::shared_ptr<Coordinate>> movementsSelectedPiece;

    SelectedPiece *selectedPiece;

    Turn *turn;
};

#endif
