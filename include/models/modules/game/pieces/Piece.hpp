#ifndef PIECE_H
#define PIECE_H

#include "models/modules/game/pieces/SelectedPiece.hpp"
#include "models/modules/game/pieces/SubjectPiece.hpp"
#include "models/modules/game/Player.hpp"

#include <set>
#include <vector>
#include <memory>

namespace models::modules::game::pieces
{
    class PieceVisitor;
    class Coordinate;
}

namespace models::modules::game::pieces::rules
{
    class MovementRulesGenerator;
}

using models::modules::game::pieces::rules::MovementRulesGenerator;

namespace models::modules::game::pieces
{
    class Piece : public SubjectPiece, public SelectedPiece
    {
    public:
        Piece(Coordinate coordinate, Player player);

        virtual ~Piece();

        Coordinate getCoordinate() const;

        Coordinate getDisplacedBy(int increase) const;

        Coordinate getDisplacedBy(const Coordinate &increase) const;

        Coordinate getDisplacedBy(const Coordinate &increase, const Coordinate &vector) const;

        std::vector<Coordinate> &getValidMovements();

        int getVectorPlayer() const;

        bool isAt(const Coordinate &coordinate) const;

        void put(Coordinate coordinate) override;

        void generateMovements() override;

        PieceSimbol getSymbol() override;

        std::vector<Coordinate> getMovements() override;

        std::vector<Coordinate> getEnPassantDiagonals() override;

        bool isMovementValid(const Coordinate &coordinate) const override;

        bool isRookAvailableForCastling() override;

        bool isKing() override;

        bool isPawn() override;

        bool isRook() override;

        bool isPromoted() const override;

        bool isPawnPromoted() override;

    protected:
        void set(Coordinate coordinate);

        Player player;

        Coordinate coordinate;

        MovementRulesGenerator *movementRulesGenerator;

        std::vector<Coordinate> validMovements;
    };
}

#endif
