#ifndef BOARD_OBSERVER_HPP
#define BOARD_OBSERVER_HPP

#include <list>
#include <memory>

class Piece;

class Coordinate;

class BoardObserver
{
public:
    virtual ~BoardObserver() = default;

    virtual void set(Piece *piece) = 0;

    virtual void set(std::list<std::shared_ptr<Coordinate>> *selectedPieceMovements) = 0;

    virtual void add(Piece *enPassantPawn) = 0;

    virtual void deleteEnPassantPawn(Piece *piece) = 0;

    virtual bool isEnemy(const Coordinate &coordinate) const = 0;

    virtual bool isSquareEmpty(const Coordinate &coordinate) const = 0;

    virtual bool isSquareOccupied(const Coordinate &coordinate) const = 0;

    virtual bool isSameColorPieceAt(const Coordinate &coordinate) const = 0;
};

#endif
