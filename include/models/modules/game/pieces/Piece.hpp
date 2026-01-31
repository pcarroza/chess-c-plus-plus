#ifndef PIECE_H
#define PIECE_H

#include "models/modules/game/pieces/SelectedPiece.hpp"
#include "models/modules/game/pieces/PieceSubject.hpp"
#include "models/modules/game/Player.hpp"

#include <set>
#include <list>
#include <memory>

namespace models::modules::game::pieces
{
    class PieceVisitor;
    class Coordinate;
}

namespace models::modules::game::pieces::rules
{
    class MovementRulesBaseGenerator;
}

namespace models::modules::game::pieces
{
    class Piece : public PieceSubject, public SelectedPiece
    {
    public:
        Piece(Coordinate *coordinate, Player color);

        virtual ~Piece();

        std::list<std::shared_ptr<Coordinate>> &getValidMovements();

        Coordinate *getCoordinate() const;

        Coordinate *getDisplacedBy(int increase) const;

        Coordinate *getDisplacedBy(const Coordinate &increase) const;

        Coordinate *getDisplacedBy(const Coordinate &increase, const Coordinate &vector);

        bool isAt(const Coordinate &coordinate);

        void put(Coordinate *coordinate) override;

        bool isMovementValid(const Coordinate &coordinate) override;

        void generateMovements() override;

        virtual void accept(PieceVisitor &visitor) = 0;

        virtual std::string toString() const = 0;

    protected:
        void set(Coordinate *coordinate);

        Player player;

        Coordinate *coordinate;

        rules::MovementRulesBaseGenerator *basedGenerator;
    };
}

#endif
