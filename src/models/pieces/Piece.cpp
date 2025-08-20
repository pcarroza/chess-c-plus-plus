#include "models/pieces/Coordinate.hpp"
#include "models/pieces/Piece.hpp"
#include "models/Color.hpp"

Piece::Piece(Coordinate *coordinate, Color color) : color(color), coordinate(coordinate), ruleBasedCoordinateGenerator(nullptr)
{
}

Piece::~Piece()
{
    delete coordinate;
    delete ruleBasedCoordinateGenerator;
}

void Piece::set(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

void Piece::put(Coordinate *target)
{
    set(target);
}

Coordinate *Piece::getCoordinate()
{
    return coordinate;
}

Coordinate *Piece::getDisplacedBy(int displacement)
{
    return new Coordinate(0, displacement);
}

Coordinate *Piece::getDisplacedBy(const Coordinate &displacement)
{
    return new Coordinate(0, 0);
}

Coordinate *Piece::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector)
{
    return new Coordinate(0, 0);
}

bool Piece::has(Coordinate &coordinate)
{
    return *getCoordinate() == coordinate;
}

bool Piece::isMovementValid(const Coordinate &target)
{
    return ruleBasedCoordinateGenerator->isMovementValid(target);
}

void Piece::generateMovements()
{
    ruleBasedCoordinateGenerator->generate();
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
