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

    Coordinate *getDisplacedBy(int displacement) const;

    Coordinate *getDisplacedBy(const Coordinate &displacement) const;

    Coordinate *getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const;

    Coordinate *scaleBy(const Coordinate &factor) const;

    bool operator==(const Coordinate &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

private:
    int row;

    int column;
};

#endif
