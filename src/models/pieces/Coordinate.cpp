#include "models/pieces/Coordinate.hpp"

Coordinate::Coordinate(int row, int column) : row(row), column(column) {}

Coordinate::Coordinate() : row(0), column(0) {}

int Coordinate::getRow() const
{
    return row;
}

int Coordinate::getColumn() const
{
    return column;
}

bool Coordinate::operator==(const Coordinate &other) const
{
    return row == other.row && column == other.column;
}

Coordinate *Coordinate::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const
{
    return Coordinate(displacement).scaleBy(vector);
}

Coordinate *Coordinate::getDisplacedBy(const Coordinate &displacement) const
{
    return new Coordinate(getRow() + displacement.getRow(), getColumn() + displacement.getColumn());
}

Coordinate *Coordinate::getDisplacedBy(int displacement) const
{
    return new Coordinate(getRow() + displacement, getColumn() + displacement);
}

Coordinate *Coordinate::scaleBy(const Coordinate &factor) const
{
    return new Coordinate(getRow() * factor.getRow(), getColumn() * factor.getColumn());
}

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate)
{
    os << "Coordinate(" << coordinate.row << ", " << coordinate.column << ")";
    return os;
}
