#ifndef SELECTED_PIECE_HPP
#define SELECTED_PIECE_HPP

class Coordinate;

class SelectedPiece
{
public:
    virtual ~SelectedPiece() = default;

    virtual void put(Coordinate *coordinate) = 0;

    virtual bool isMovementValid(const Coordinate &coordinate) = 0;

    virtual bool isThePawnPromoted() = 0;

    virtual void generateMovements() = 0;
};

#endif
