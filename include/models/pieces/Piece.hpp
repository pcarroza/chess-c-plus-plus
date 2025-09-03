#ifndef PIECE_H
#define PIECE_H

#include <set>
#include <list>

#include "models/pieces/rulesOfMovements/MovementRulesBaseGenerator.hpp"
#include "models/pieces/PieceVisitor.hpp"
#include "models/pieces/Coordinate.hpp"
#include "models/Player.hpp"
#include "SelectedPiece.hpp"
#include "PieceSubject.hpp"

namespace models::pieces::rulesOfMovements
{
    class MovementRulesBaseGenerator;
}

using models::pieces::rulesOfMovements::MovementRulesBaseGenerator;

class Piece : public PieceSubject, public SelectedPiece
{
public:
    Piece(Coordinate *coordinate, Player color);

    virtual ~Piece();

    std::list<std::shared_ptr<Coordinate>> &getValidMovements();

    Coordinate *getCoordinate() const;

    Coordinate *getDisplacedBy(int displacement) const;

    Coordinate *getDisplacedBy(const Coordinate &displacement) const;

    Coordinate *getDisplacedBy(const Coordinate &displacement, const Coordinate &vector);

    bool isAt(const Coordinate &coordinate);

    virtual void put(Coordinate *coordinate) override;

    virtual bool isMovementValid(const Coordinate &coordinate) override;

    virtual void generateMovements() override;

    virtual void accept(PieceVisitor &visitor) = 0;

    virtual std::string toString() const = 0;

protected:
    void set(Coordinate *coordinate);

protected:
    Player player;

    Coordinate *coordinate;

    MovementRulesBaseGenerator *basedGenerator;
};

#endif