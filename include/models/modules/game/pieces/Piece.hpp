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

        std::vector<Coordinate> &getValidMovements();

        int getVectorPlayer() const;

        bool isAt(const Coordinate &coordinate) const;

        void put(Coordinate coordinate) override;

        bool isMovementValid(const Coordinate &coordinate) override;

        void generateMovements() override;

        Coordinate getCoordinate() const;

        Coordinate getDisplacedBy(int increase) const;

        Coordinate getDisplacedBy(const Coordinate &increase) const;

        Coordinate getDisplacedBy(const Coordinate &increase, const Coordinate &vector) const;

        virtual void accept(PieceVisitor &pieceVisitor) = 0;

        virtual std::string toString() const = 0;

    protected:
        void set(Coordinate coordinate);

        Player player;

        Coordinate coordinate;

        MovementRulesGenerator *movementRulesGenerator;

        std::vector<Coordinate> validMovements;
    };
}

#endif
