#include "models/modules/game/pieces/Coordinate.hpp"
#include "models/modules/game/pieces/Piece.hpp"
#include "models/modules/game/Player.hpp"
#include "models/modules/game/pieces/rules/MovementRulesFacade.hpp"
#include "models/modules/game/pieces/rules/MovementRulesGenerator.hpp"

using models::modules::game::Player;
using models::modules::game::pieces::rules::MovementRulesFacade;

namespace models::modules::game::pieces
{
    Piece::Piece(Coordinate coordinate, Player player)
        : player(player),
          coordinate(coordinate),
          movementRulesGenerator(nullptr)
    {
        validMovements.reserve(27);
    }

    Piece::~Piece()
    {
    }

    void Piece::set(Coordinate coordinate)
    {
        this->coordinate = coordinate;
    }

    std::vector<Coordinate> &Piece::getValidMovements()
    {
        return this->validMovements;
    }

    void Piece::generateMovements()
    {
        validMovements.clear();
        movementRulesGenerator->generate(*this, validMovements);
    }

    int Piece::getVectorPlayer() const
    {
        return this->player.getVector();
    }

    void Piece::put(Coordinate target)
    {
        set(target);
    }

    Coordinate Piece::getCoordinate() const
    {
        return coordinate;
    }

    Coordinate Piece::getDisplacedBy(int displacement) const
    {
        return getCoordinate().getDisplacedBy(displacement);
    }

    Coordinate Piece::getDisplacedBy(const Coordinate &displacement) const
    {
        return getCoordinate().getDisplacedBy(displacement);
    }

    Coordinate Piece::getDisplacedBy(const Coordinate &displacement, const Coordinate &vector) const
    {
        return getCoordinate().getDisplacedBy(displacement, vector);
    }

    bool Piece::isAt(const Coordinate &coordinate) const
    {
        return getCoordinate() == coordinate;
    }

    std::vector<Coordinate> Piece::getMovements() const
    {
        return std::vector<Coordinate>();
    }

    std::vector<Coordinate> Piece::getEnPassantDiagonals() const
    {
        return std::vector<Coordinate>();
    }

    bool Piece::isMovementValid(const Coordinate &target) const
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

    bool Piece::isRookAvailableForCastling() const
    {
        return false;
    }

    bool Piece::isKing() const
    {
        return false;
    }

    bool Piece::isPawn() const
    {
        return false;
    }

    bool Piece::isRook() const
    {
        return false;
    }

    bool Piece::isPromoted() const
    {
        return false;
    }

    bool Piece::isPawnPromoted() const
    {
        return false;
    }

    PieceSymbol Piece::getSymbol() const
    {
        return PieceSymbol::EMPTY;
    }
}
