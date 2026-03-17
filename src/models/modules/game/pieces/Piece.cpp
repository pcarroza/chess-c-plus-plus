#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"
#include "models/modules/game/pieces/rules/MovementRulesGenerator.hpp"

using models::modules::game::Player;
using models::modules::game::pieces::rules::MovementRulesFacade;

namespace models::modules::game::pieces
{
    Piece::Piece(Coordinate *coordinate, Player player)
        : player(player),
          coordinate(coordinate),
          movementRulesGenerator(nullptr)
    {
        validMovements.reserve(27);
    }

    Piece::~Piece()
    {
        delete coordinate;
    }

    void Piece::set(Coordinate *coordinate)
    {
        this->coordinate = coordinate;
    }

    std::vector<Coordinate> &Piece::getValidMovements()
    {
        return this->validMovements;
    }

    int Piece::getVectorPlayer() const
    {
        return this->player.getVector();
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

    Coordinate Piece::getDisplacedBy(int displacement) const
    {
        return getCoordinate()->getDisplacedBy(displacement);
    }

    Coordinate Piece::getDisplacedBy(const Coordinate &displacement) const
    {
        return getCoordinate()->getDisplacedBy(displacement);
    }

    Coordinate Piece::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const
    {
        return getCoordinate()->getDisplacedBy(displacement, vector);
    }

    bool Piece::isAt(const Coordinate &coordinate) const
    {
        return *getCoordinate() == coordinate;
    }

    bool Piece::isMovementValid(const Coordinate &target)
    {
        for (const auto &movement : validMovements)
        {
            if (movement == target)
            {
                return true;
            }
        }
        return false;
    }

    void Piece::generateMovements()
    {
        this->validMovements.clear();
        movementRulesGenerator->generate(*this, this->validMovements);
    }
}
