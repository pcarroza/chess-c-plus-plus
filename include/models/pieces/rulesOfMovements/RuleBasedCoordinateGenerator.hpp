#ifndef MOVE_RULES_MANAGER_HPP
#define MOVE_RULES_MANAGER_HPP

#include "models/pieces/Coordinate.hpp"
#include "../Piece.hpp"

#include <list>
#include <memory>
#include <algorithm>

class Coordinate;
class Piece;

namespace models::pieces::rulesOfMovements
{
    class MovementRulesBaseGenerator
    {
    public:
        MovementRulesBaseGenerator(Piece &piece);

        virtual ~MovementRulesBaseGenerator() = default;

        std::list<std::shared_ptr<Coordinate>> getValidMovements();

        bool isMovementValid(const Coordinate &coordinate);

        virtual void generate() = 0;

    private:
        bool isContained(const Coordinate &coordinate);

    protected:
        Piece &piece;

        std::list<std::shared_ptr<Coordinate>> possibleMoves;
    };
}

#endif
