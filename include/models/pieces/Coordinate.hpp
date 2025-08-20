#ifndef COORDINATE_H
#define COORDINATE_H

#include <ostream>

class Coordinate
{
public:
    Coordinate(int row, int column);

    Coordinate(const Coordinate &other) = default;

    Coordinate();

    int getRow() const;

    int getColumn() const;

    bool operator==(const Coordinate &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

private:
    int row;

    int column;
};

#endif
