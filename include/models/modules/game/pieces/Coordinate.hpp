#ifndef COORDINATE_H
#define COORDINATE_H

#include <ostream>

namespace models::modules::game::pieces
{
    class Coordinate
    {
    public:
        Coordinate(int row, int column);

        Coordinate(const Coordinate &other) = default;

        Coordinate();

        int getRow() const;

        int getColumn() const;

        Coordinate getDisplacedBy(int displacement) const;

        Coordinate getDisplacedBy(const Coordinate &displacement) const;

        Coordinate getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const;

        Coordinate scaleBy(const Coordinate &factor) const;

        bool operator==(const Coordinate &other) const;

    private:
        int row;

        int column;
    };
}

#endif
