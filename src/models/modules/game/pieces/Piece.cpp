#include "models/modules/game/pieces/PieceVisitor.hpp"
#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/rules/MovementRulesBaseGenerator.hpp"

using models::modules::game::Player;
using models::modules::game::pieces::rules::MovementRulesBaseGenerator;

namespace models::modules::game::pieces
{
    Piece::Piece(Coordinate *coordinate, Player player)
        : player(player),
          coordinate(coordinate),
          basedGenerator(nullptr)
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

    std::list<std::shared_ptr<Coordinate>> &Piece::getValidMovements()
    {
        return basedGenerator->getMovements();
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

    Coordinate *Piece::getDisplacedBy(int displacement) const
    {
        return getCoordinate()->getDisplacedBy(displacement);
    }

    Coordinate *Piece::getDisplacedBy(const Coordinate &displacement) const
    {
        return getCoordinate()->getDisplacedBy(displacement);
    }

    Coordinate *Piece::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const
    {
        return getCoordinate()->getDisplacedBy(displacement, vector);
    }

    bool Piece::isAt(const Coordinate &coordinate) const
    {
        return *getCoordinate() == coordinate;
    }

    bool Piece::isMovementValid(const Coordinate &target)
    {
        return basedGenerator->isMovementValid(target);
    }

    void Piece::generateMovements()
    {
        basedGenerator->generate(*this);
    }
}
