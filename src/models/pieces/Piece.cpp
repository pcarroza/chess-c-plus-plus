#include "models/pieces/Coordinate.hpp"
#include "models/pieces/Piece.hpp"
#include "models/Player.hpp"

Piece::Piece(Coordinate *coordinate, Player color) : player(color), coordinate(coordinate), basedGenerator(nullptr)
{
}

Piece::~Piece()
{
    delete coordinate;
    delete basedGenerator;
}

void Piece::set(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

void Piece::put(Coordinate *target)
{
    if (coordinate != nullptr)
    {
        delete coordinate;
        coordinate = nullptr;
    }
    set(target);
}

Coordinate *Piece::getCoordinate() const
{
    return coordinate;
}

Coordinate *Piece::getDisplacedBy(int displacement) const
{
    return getCoordinate()->getDisplacedBy(displacement);
}

Coordinate *Piece::getDisplacedBy(const Coordinate &displacement) const
{
    return getCoordinate()->getDisplacedBy(displacement);
}

Coordinate *Piece::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector)
{
    return getCoordinate()->getDisplacedBy(displacement, vector);
}

bool Piece::has(Coordinate &coordinate)
{
    return *getCoordinate() == coordinate;
}

bool Piece::isMovementValid(const Coordinate &target)
{
    return basedGenerator->isMovementValid(target);
}

void Piece::generateMovements()
{
    basedGenerator->generate();
}

bool Piece::isThePawnPromoted()
{
    return false;
}

bool Piece::isNotMoved()
{
    return true;
}

bool Piece::isKing()
{
    return false;
}

bool Piece::isRook()
{
    return false;
}

bool Piece::isVulnerablePawn()
{
    return false;
}
