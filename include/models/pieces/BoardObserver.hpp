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

    virtual void set(std::list<std::shared_ptr<Coordinate>> coordinates) = 0;

    virtual void add(Piece *enPassantPawn) = 0;

    virtual bool isItEnemy(const Coordinate &coordinate) const = 0;

    virtual bool isBoxEmpty(const Coordinate &coordinate) const = 0;

    virtual bool isBoxOccupied(const Coordinate &coordinate) const = 0;

    virtual bool someColor(const Coordinate &coordinate) const = 0;
};

#endif
