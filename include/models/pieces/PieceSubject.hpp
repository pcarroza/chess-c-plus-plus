#ifndef PIECE_SUBJECT_HPP
#define PIECE_SUBJECT_HPP

#include "BoardObserver.hpp"

class PieceSubject
{
public:

    virtual ~PieceSubject() = default;

    void subscribe(BoardObserver *boardObserver);

    bool isItEnemy(const Coordinate &coordinate) const;

    bool sameColor(const Coordinate &coordinate) const;

    bool isBoxOccupied(const Coordinate &coordinate) const;

    void addPassantPawn(Piece *piece);

protected:
    BoardObserver *boardObserver;
};

#endif
