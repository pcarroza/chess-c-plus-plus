#ifndef PIECE_SUBJECT_HPP
#define PIECE_SUBJECT_HPP

#include "BoardObserver.hpp"

class PieceSubject
{
public:

    virtual ~PieceSubject() = default;

    void subscribe(BoardObserver *boardObserver);

    bool isItEnemy(const Coordinate &coordinate);

    bool sameColor(const Coordinate &coordinate);

    bool isBoxOccupied(const Coordinate &coordinate);

    void addPassantPawn(Piece *piece);

protected:
    BoardObserver *boardObserver;
};

#endif
