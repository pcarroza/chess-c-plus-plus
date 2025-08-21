#include "models/pieces/Pawn.hpp"
#include "models/pieces/rulesOfMovements/MovementRulesBaseGeneratorFacade.hpp"

using models::pieces::rulesOfMovements::MovementRulesBaseGeneratorFacade;

Pawn::Pawn(Coordinate *coordinate, Color color)
    : Piece(coordinate, color),
      initialState(true),
      isItPromoted(false),
      vulnerablePawn(false)
{
    basedGenerator = MovementRulesBaseGeneratorFacade::createPawnRuleBasedCoordinateGenerator(this);
}

void Pawn::put(Coordinate *target)
{
    if (isInitialState())
    {
        close();
    }

    if (inStep(*target))
    {
        vulnerablePawn = true;
        addPassantPawn(this);
    }
    else
    {
        vulnerablePawn = false;
    }

    if (isThePawnPromoted(*target))
    {
        changeToPromoted();
    }

    delete coordinate;

    Piece::put(target);
}

bool Pawn::isInitialState()
{
    return false;
}

void Pawn::close()
{
    initialState = false;
}

bool Pawn::inStep(Coordinate &target)
{
    return false;
}

bool Pawn::isMovementValid(const Coordinate &target)
{
    Coordinate nonConstTarget = target;
    return Piece::isMovementValid(target);
}

void Pawn::generateMovements()
{
    Piece::generateMovements();
}

bool Pawn::isThePawnPromoted()
{
    return false;
}

bool Pawn::isThePawnPromoted(Coordinate &coordinate)
{
    return false;
}

void Pawn::changeToPromoted()
{
    isItPromoted = true;
}

bool Pawn::isWhite()
{
    return color == Color::WHITE;
}

bool Pawn::isBlack()
{
    return color == Color::BLACK;
}

bool Pawn::isVulnerablePawn()
{
    return vulnerablePawn;
}

std::string Pawn::toString() const
{
    return "Pawn()";
}
