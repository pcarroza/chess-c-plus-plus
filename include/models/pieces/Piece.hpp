#ifndef PIECE_H
#define PIECE_H

#include <set>
#include <list>

#include "./rulesOfMovements/RuleBasedCoordinateGenerator.hpp"
#include "SelectedPiece.hpp"
#include "PieceSubject.hpp"
#include "models/pieces/Coordinate.hpp"
#include "models/Color.hpp"

namespace models::pieces::rulesOfMovements
{
    class MovementRulesBaseGeneratorGenerator;
}

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorGenerator;

class Piece : public PieceSubject, public SelectedPiece
{
public:
    Piece(Coordinate *coordinate, Color color);

    virtual ~Piece();

    virtual void put(Coordinate *coordinate) override;

    virtual bool isMovementValid(const Coordinate &coordinate) override;

    virtual bool isThePawnPromoted() override;

    virtual void generateMovements() override;

    virtual bool isVulnerablePawn();

    std::list<Coordinate> getValidMovements();

    Coordinate *getCoordinate();

    Coordinate *getDisplacedBy(int displacement);

    Coordinate *getDisplacedBy(const Coordinate &displacement);

    Coordinate *getDisplacedBy(const Coordinate &displacement, const Coordinate &vector);

    bool has(Coordinate &coordinate);

    bool isNotMoved();

    bool isKing();

    bool isRook();

    virtual std::string toString() const = 0;

protected:
    void set(Coordinate *coordinate);

protected:
    Color color;

    Coordinate *coordinate;

    MovementRulesBaseGeneratorGenerator *basedGenerator;
};

#endif