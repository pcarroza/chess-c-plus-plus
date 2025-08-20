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

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate)
{
    os << "Coordinate(" << coordinate.row << ", " << coordinate.column << ")";
    return os;
}
